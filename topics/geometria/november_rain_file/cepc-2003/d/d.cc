/*
  Solution for DIC (Dice contest)
  Tomek Czajka

  The solution:
  - enumerate dice states; by state we mean orientation and y-position
    of the die; there are 96 states
  - generate the state graph; edges represent rolling the die; for
    each edge we have the weight and dx (change in x-position; can
    be -1,0,+1)
  - the problem is to find the shortest path length from the start
    state to one of the end states (final orientation does not matter),
    with total dx given (x2-x1); x2-x1>=0 (if x2<x1, we do mirror reflection
    of the problem)
  - first we find shortest path lengths with dx=0 and dx=1, for each
    pair of states, using Dijkstra algorithm; we don't know how far
    left or right it might be useful to go, so it is a Dijkstra on
    an infinite graph of states * x-positions;
    I don't know how long this can take; we stop as soon as we reach
    all reachable states with x=0 or x=1; only half of the states are
    reachable (the sum of dots on top, front and left side of the die
    changes parity with each move)
  - from the shortest paths for dx=k, we can calculate shortest paths
    for dx=2k and dx=2k+1 in O(n^3) time; we get the shortest paths
    for the given dx=x2-x1 in O(n^3 * log(x2-x1)) time
*/

#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const long long INF = 1LL << 60; // infinity
const int MAXY = 4; // width of the ribbon
const int NSTATES = 24 * MAXY; // number of states

struct State {
  int y; // y position
  int top,front,left; // dots on top,front,left sides
  State() {}
  State(int y,int t,int f,int l):y(y),top(t),front(f),left(l) {}
};

struct Edge {
  int s;       // new state
  int dx;      // can be -1,0,+1
  long long w; // weight
  Edge() {}
  Edge(int s,int dx,long long w):s(s),dx(dx),w(w) {}
};

/* INPUT DATA */
long long dieNumbers[7]; // numbers on the sides of the die [1..6]
int startx,starty,endx,endy; // start and end positions

/* REST OF GLOBALS */
vector<Edge> edges[NSTATES]; // state graph
long long dx01[2][NSTATES][NSTATES]; // path lengths for dx=0 or 1
long long paths[NSTATES][NSTATES]; // shortest path lengths for some given dx


void read() {
  for(int i=1;i<=6;++i)
    scanf("%lld",&dieNumbers[i]);
  scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
}

// is the die properly oriented (as in the picture) ?
bool goodOrientation(int top,int front,int left) {
  bool res=true;
  if(top>3) { top=7-top; res=!res; }
  if(front>3) { front=7-front; res=!res; }
  if(left>3) { left=7-left; res=!res; }
  // (top,front,left)=(1,2,3),(2,3,1),(3,1,2) would be good
  if((top+1)%3 != front%3) res=!res;
  return res;
}


// State -> 0..NSTATES-1
int encodeState(const State &s) {
  int res=24*(s.y-1);
  res += 4 * (s.top-1);
  int c=0;
  for(int i=1;i<=6;++i) if(i!=s.top && i!=7-s.top) {
    if(i==s.front) res+=c;
    ++c;
  }
  return res;
}

// 0..NSTATES-1 -> State
State decodeState(int x) {
  State s;
  s.y = x/24 + 1; x%=24;
  s.top = x/4 + 1; x%=4;
  int c=0;
  for(int i=1;i<=6;++i) if(i!=s.top && i!=7-s.top) {
    if(c==x) s.front = i;
    ++c;
  }
  // now calculate s.left from s.top and s.left
  s.left = 1;
  while(s.left==s.top || s.left==7-s.top || s.left==s.front ||
        s.left==7-s.front)
    ++s.left;
  if(!goodOrientation(s.top,s.front,s.left))
    s.left = 7-s.left;
  return s;
}

void calcGraph() {
  for(int i=0;i<NSTATES;++i) {
    State s = decodeState(i);
    State s2;
    // up
    if(s.y<MAXY) {
      s2.y = s.y+1;
      s2.top = s.front;
      s2.front = 7 - s.top;
      s2.left = s.left;
      edges[i].push_back(Edge(encodeState(s2),0,dieNumbers[s2.top]));
    }
    // down
    if(s.y>1) {
      s2.y = s.y-1;
      s2.top = 7 - s.front;
      s2.front = s.top;
      s2.left = s.left;
      edges[i].push_back(Edge(encodeState(s2),0,dieNumbers[s2.top]));
    }
    // left
    {
      s2.y = s.y;
      s2.top = 7 - s.left;
      s2.front = s.front;
      s2.left = s.top;
      edges[i].push_back(Edge(encodeState(s2),-1,dieNumbers[s2.top]));
    }
    // right
    {
      s2.y = s.y;
      s2.top = s.left;
      s2.front = s.front;
      s2.left = 7 - s.top;
      edges[i].push_back(Edge(encodeState(s2),+1,dieNumbers[s2.top]));
    }
  }
}

// for calc01 Dijkstra algorithm
struct QueueElem {
  long long d; // distance
  int x;       // x position
  int s;       // state
  QueueElem() {}
  QueueElem(long long d,int x,int s):d(d),x(x),s(s) {}
};

inline bool operator<(const QueueElem &a, const QueueElem &b) {
  return a.d > b.d;
}

/* Dijkstra algorithm, start with state s, calculate dx01[...][s][...] */
void calc01(int start) {
  for(int dx=0;dx<=1;++dx)
    for(int x=0;x<NSTATES;++x)
      dx01[dx][start][x] = INF;
  int todo = NSTATES; // half of 2*NSTATES
  priority_queue<QueueElem> q;
  set<int> done; // which pairs (x,s) are "done" by Dijkstra;
                 // store (x*NSTATES+s) for simplicity
  q.push(QueueElem(0,0,start));
  for(;;) {
    QueueElem qe = q.top(); q.pop();
    int x=qe.x; int s=qe.s; long long d=qe.d;
    if(done.find(x*NSTATES+s)!=done.end()) continue;
    done.insert(x*NSTATES+s);
    if(x==0 || x==1) {
      dx01[x][start][s] = d;
      if(--todo == 0) break;
    }
    for(vector<Edge>::iterator it=edges[s].begin();it!=edges[s].end();++it) {
      q.push(QueueElem(d + it->w, x + it->dx, it->s));
    }
  }
}

// join paths given by a and b, result in paths
void joinPaths(long long a[NSTATES][NSTATES], long long b[NSTATES][NSTATES]) {
  static long long res[NSTATES][NSTATES];
  
  for(int x=0;x<NSTATES;++x)
    for(int y=0;y<NSTATES;++y) {
      long long r = INF;
      for(int z=0;z<NSTATES;++z)
        r = min(r, a[x][z] + b[z][y]);
      res[x][y] = r;
    }
  
  for(int x=0;x<NSTATES;++x)
    for(int y=0;y<NSTATES;++y)
      paths[x][y] = res[x][y];
}

// calculate paths[][] for given dx>=0
void calcPaths(int dx) {
  if(dx<=1) {
    for(int x=0;x<NSTATES;++x)
      for(int y=0;y<NSTATES;++y)
        paths[x][y] = dx01[dx][x][y];
  }
  else {
    if(dx%2==0) {
      calcPaths(dx/2);
      joinPaths(paths,paths);
    }
    else {
      calcPaths(dx-1);
      joinPaths(paths,dx01[1]);
    }
  }
}

// assumes paths is calculated for dx=endx-startx
long long calcResult() {
  long long res = INF;

  int st = encodeState(State(starty,1,2,3));
  for(int i=0;i<NSTATES;++i) {
    State s = decodeState(i);
    if(s.y==endy)
      res = min(res, paths[st][i]);
  }
  return res;
}

int main() {
  read();
  if(startx > endx) {
    // mirror reflection
    swap(startx,endx);
    swap(dieNumbers[3],dieNumbers[4]);
  };
  calcGraph();
  for(int x=0;x<NSTATES;++x)
    calc01(x);
  calcPaths(endx-startx);
  long long res = calcResult();
  printf("%lld\n",res);
}
