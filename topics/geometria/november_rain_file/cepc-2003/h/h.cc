/*
  CEPC 2003
  Solution for Computer
  Tomek Czajka

  The solution:
  - calculate the set of "important" registers; a register is important
    if its value can influence a decision during a conditional jump;
    important registers are calculated as the nodes of
    the forest with JZ registers as roots and AND/OR/XOR/MOV instructions
    as edges (dependencies); there are at most 15 important registers
  - nregisters = number of important registers
  - registers are renumerated so that the important registers
    are 0..nregisters-1; the instructions calculating unimportant registers
    are changed to NOP (no operation)
  - BFS on computers states is run to find the shortest path from a
    starting state to an end state; a state is the contents of the
    registers and instruction pointer; there are at most 2^15 * 16 =
    512K states
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_NINSTR = 16; // maximum number of instructions
const int ALL_REGISTERS = 32; // number of registers
const int MAX_NREGISTERS = 15; // maximum number of important registers

const int INSTR_AND = 0;
const int INSTR_OR = 1;
const int INSTR_XOR = 2;
const int INSTR_NOT = 3;
const int INSTR_MOV = 4;
const int INSTR_SET = 5;
const int INSTR_RANDOM = 6;
const int INSTR_JMP = 7;
const int INSTR_JZ = 8;
const int INSTR_STOP = 9;
const int INSTR_NOP = 10;

const char *INSTR_NAMES[] = { "AND","OR","XOR","NOT",
  "MOV","SET","RANDOM","JMP","JZ","STOP","NOP" };
const int INSTR_ARG[] = { 2,2,2,1,2,2,1,1,2,0,1 };

const int INF = 1000000000; // infinity


struct Instr {
  int op,a,b;
};

int ninstr; // number of instructions
Instr program[MAX_NINSTR];

bool important[ALL_REGISTERS];
int nregisters; // number of important registers


void read() {
  char buf[10];
  scanf("%d",&ninstr);
  for(int i=0;i<ninstr;++i) {
    scanf("%s",buf);
    int op=0;
    while(strcmp(buf,INSTR_NAMES[op])!=0) ++op;
    program[i].op = op;
    if(INSTR_ARG[op]>=1) scanf("%d",&program[i].a);
    if(INSTR_ARG[op]>=2) scanf("%d",&program[i].b);
  }
}

void dfsImportant(int x) {
  if(important[x]) return;
  important[x] = true;
  for(int i=0;i<ninstr;++i) {
    if((program[i].op == INSTR_AND || program[i].op == INSTR_OR ||
        program[i].op == INSTR_XOR || program[i].op == INSTR_MOV) &&
        program[i].a == x) {
      dfsImportant(program[i].b);
    }
  }
}

void calcImportant() {
  for(int i=0;i<ALL_REGISTERS;++i) important[i]=false;
  for(int i=0;i<ninstr;++i) if(program[i].op == INSTR_JZ) dfsImportant(program[i].b);
}

void renum() {
  int newNum[ALL_REGISTERS];
  nregisters = 0;
  for(int i=0;i<ALL_REGISTERS;++i) {
    if(important[i]) newNum[i] = nregisters++;
    else newNum[i] = -1;
  }
  for(int i=0;i<ninstr;++i) {
    switch(program[i].op) {
      case INSTR_AND: case INSTR_OR: case INSTR_XOR: case INSTR_MOV:
        program[i].a = newNum[program[i].a];
        program[i].b = newNum[program[i].b];
        if(program[i].a == -1) program[i].op = INSTR_NOP;
        break;
      case INSTR_NOT: case INSTR_SET: case INSTR_RANDOM:
        program[i].a = newNum[program[i].a];
        if(program[i].a == -1) program[i].op = INSTR_NOP;
        break;
      case INSTR_JZ:
        program[i].b = newNum[program[i].b];
        break;
    }
  }
}

int bfs() {
  /* we represent state with an int - lower NREGISTERS bits are registers,
   * state >> NREGISTERS is program counter */
  static int dist[MAX_NINSTR << MAX_NREGISTERS]; // 2 MB
  int nstates = ninstr << nregisters;  // <= 512 K
  for(int i=0;i<nstates;++i) dist[i] = INF;
  queue<int> q;
  // all states with PC = 0  -- starting states
  for(int s=0;s<(1<<nregisters);++s) {
    q.push(s);
    dist[s] = 0;
  }
  while(!q.empty()) {
    int s = q.front(); q.pop();
    int pc = s >> nregisters;
    int regs = s & ((1<<nregisters)-1);
    int d = dist[s];
    int op = program[pc].op;
    int a = program[pc].a;
    int b = program[pc].b;
#define ADD(s) if(dist[s]==INF) { dist[s] = d+1; q.push(s); }
#define SIMPLE_INSTR int s2 = ((pc+1)<<nregisters) + regs; ADD(s2); break;
    switch(op) {
      case INSTR_AND: {
        if(((regs>>b)&1)==0)
          regs &= ~(1<<a);
        SIMPLE_INSTR;
      }
      case INSTR_OR: {
        regs |= ((regs>>b)&1)<<a;
        SIMPLE_INSTR;
      }
      case INSTR_XOR: {
        regs ^= ((regs>>b)&1)<<a;
        SIMPLE_INSTR;
      }
      case INSTR_NOT: {
        regs ^= 1<<a;;
        SIMPLE_INSTR;
      }
      case INSTR_MOV: {
        if((regs>>b)&1) regs |= 1<<a;
        else regs &= ~(1<<a);
        SIMPLE_INSTR;
      }
      case INSTR_SET: {
        if(b) regs |= 1<<a;
        else regs &= ~(1<<a);
        SIMPLE_INSTR;
      }
      case INSTR_RANDOM: {
        int s2 = ((pc+1)<<nregisters)+regs;
        s2 |= 1<<a;
        ADD(s2);
        s2 &= ~(1<<a);
        ADD(s2);
        break;
      }
      case INSTR_JMP: {
        int s2 = (a<<nregisters)+regs;
        ADD(s2);
        break;
      }
      case INSTR_JZ: {
        int s2;
        if((regs>>b)&1)
          s2 = ((pc+1)<<nregisters)+regs;
        else
          s2 = (a<<nregisters)+regs;
        ADD(s2);
        break;
      }
      case INSTR_STOP: {
        return d;
      }
      case INSTR_NOP: {
        SIMPLE_INSTR;
      }
    }
  }
#undef ADD
#undef SIMPLE_INSTR
  return INF;
}

int main() {
  read();
  calcImportant();
  // renumerate the registers in instructions, so that only 0..nregisters-1 are used
  renum();
  int res = bfs();
  if(res==INF) printf("HANGS\n");
  else printf("%d\n",res+1); // + 1 cycle for STOP instruction
}
