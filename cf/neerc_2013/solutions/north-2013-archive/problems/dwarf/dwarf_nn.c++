/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem D. Dwarf Tower                                         */
/*                                                                */
/* Original idea         Vitaly Aksenov                           */
/* Problem statement     Vitaly Aksenov                           */
/* Test set              Vitaly Aksenov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <algorithm>

const int N = 333444;
int aa[N], bb[N], cc[N], he[N], id[N], inq[N], c[N], ne[N];
int q[12345678];

bool compc(int i, int j) {
  return c[i] < c[j];
}

int main() {
  freopen("dwarf.in", "r", stdin);
  freopen("dwarf.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", c + i);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", aa + i, bb + i, cc + i);
    --aa[i];
    --bb[i];
    --cc[i];
    aa[i + m] = aa[i];
    bb[i + m] = cc[i];
    cc[i + m] = bb[i];
  }
  for (int i = 0; i < n; i++) {
    he[i] = -1;
    id[i] = i;
  }
  for (int i = 0; i < m + m; i++) {
    ne[i] = he[bb[i]];
    he[bb[i]] = i;
  }
  int head = 0;
  int tail = 0;
  std::sort(id, id + n, compc);
  for (int i = 0; i < n; i++) {
    q[tail++] = id[i];
    inq[id[i]] = true;
  }
  while (head < tail) {
    int v = q[head++];
    inq[v] = false;
    for (int e = he[v]; e >= 0; e = ne[e]) {
      if (c[v] + c[cc[e]] < c[aa[e]]) {
        c[aa[e]] = c[v] + c[cc[e]];
        if (!inq[aa[e]]) {
          inq[aa[e]] = true;
          q[tail++] = aa[e];
        }
      }
    }
  }
  printf("%d\n", c[0]);
}
