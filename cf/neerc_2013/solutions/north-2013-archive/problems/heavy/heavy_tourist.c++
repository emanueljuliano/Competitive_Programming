/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem H. Heavy Chain Clusterization                          */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Sergey Poromov                           */
/*                       Mikhail Dvorkin                          */
/* Test set              Sergey Poromov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Gennady Korotkevich                      */
/******************************************************************/

#include <stdio.h>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int co = 239042017;
const int N = 123456;

int m, fin;
int ss[N], ff[N], c[N], f[N], obr[N], d[N], x[N], pred[N], last[N];

void add(int x, int y, int z, int xx, int yy) {
  m++;
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  obr[m] = yy;
}

bool expath() {
  for (int i = 0; i <= fin; i++) d[i] = -1;
  int b = 1, e = 1;
  x[1] = 0;
  d[0] = 0;
  while (b <= e) {
    int j = last[x[b]];
    while (j > 0) {
      if (c[j] > f[j] && d[ff[j]] == -1) {
        e++;
        x[e] = ff[j];
        d[x[e]] = d[x[b]] + 1;
        if (x[e] == fin) return true;
      }
      j = pred[j];
    }
    b++;
  }
  return false;
}

int rec(int v, int w) {
  if (v == fin) return w;
  int r = 0;
  int j = last[v];
  while (j > 0) {
    last[v] = pred[j];
    if (c[j] > f[j] && d[ff[j]] == d[v] + 1) {
      int ww = c[j] - f[j];
      if (w - r < ww) ww = w - r;
      int t = rec(ff[j], ww);
      if (t > 0) {
        f[j] += t;
        if (obr[j] != 0) f[obr[j]] -= t;
        r += t;
        if (r == w) break;
      }
    }
    j = pred[j];
  }
  return r;
}

map <long long, int> lmap, rmap;
char s[N][555];
long long pw[555];
int from[N], to[N], st[N];
bool was[N];

int main() {
  freopen("heavy.in", "r", stdin);
  freopen("heavy.out", "w", stdout);
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int lcnt = 0, rcnt = 0;
  for (int i = 0; i < n; i++) {
    int len = strlen(s[i]);
    long long hl = 0, hr = 0;
    for (int j = 0; j < k; j++) hl = hl * co + s[i][j];
    for (int j = 0; j < k; j++) hr = hr * co + s[i][len - j - 1];
    if (lmap.find(hl) == lmap.end()) {
      lmap[hl] = ++lcnt;
    }
    if (rmap.find(hr) == rmap.end()) {
      rmap[hr] = ++rcnt;
    }
    from[i] = lmap[hl];
    to[i] = rmap[hr];
  }
  fin = lcnt + rcnt + 1;
  m = 0;
  for (int i = 1; i <= lcnt; i++) add(0, i, 1, 0, 0);
  for (int i = lcnt + 1; i <= lcnt + rcnt; i++) add(i, fin, 1, 0, 0);
  for (int i = 0; i < n; i++) {
    add(from[i], lcnt + to[i], 1000000, 0, m + 2);
    add(lcnt + to[i], from[i], 0, 0, m);
  }
  for (int i = 0; i <= fin; i++) last[i] = 0;
  for (int i = 1; i <= m; i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i = 0; i <= fin; i++) st[i] = last[i];
  int ans = 0;
  while (expath()) {
    int t = rec(0, (int)1e9);
    ans += t;
    for (int i = 0; i <= fin; i++) last[i] = st[i];
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) was[i] = false;
  for (int i = 1; i <= lcnt + rcnt; i++)
    if (d[ss[i]] != -1 && d[ff[i]] == -1) {
      vector <int> ret;
      for (int j = 0; j < n; j++)
        if (from[j] == i || lcnt + to[j] == i)
          if (!was[j]) {
            was[j] = true;
            ret.push_back(j + 1);
          }
      int sz = ret.size();
      printf("%d", sz);
      for (int j = 0; j < sz; j++) printf(" %d", ret[j]);
      printf("\n");
    }
  return 0;
}

