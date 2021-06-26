/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem B. Ballot Analyzing Device                             */
/*                                                                */
/* Original idea         Jury                                     */
/* Problem statement     Andrew Stankevich                        */
/* Test set              Andrew Stankevich                        */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

string name[123];
int id[123], ff[123];

bool compff(int i, int j) {
  return ff[i] > ff[j] || (ff[i] == ff[j] && i < j);
}

int main() {
  freopen("bad.in", "r", stdin);
  freopen("bad.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int c = getchar();
    while (c <= 32) c = getchar();
    name[i] = "";
    while (c > 32) {
      name[i] += (char) c;
      c = getchar();
    }
    id[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int c = getchar();
    while (c <= 32) {
      c = getchar();
    }
    int cn = 0;
    int who = -1;
    for (int j = 0; j < n; j++) {
      if (c == 'X') {
        ++cn;
        who = j;
      }
      c = getchar();
    }
    if (cn == 1) {
      ++ff[who];
    } else {
      ff[n]++;
    }
  }
  std::sort(id, id + n, compff);
  for (int i = 0; i < n; i++) {
    printf("%s %.2lf%%\n", name[id[i]].c_str(), 100. * ff[id[i]] / m);
  }
  printf("Invalid %.2lf%%\n", 100. * ff[n] / m);
}
