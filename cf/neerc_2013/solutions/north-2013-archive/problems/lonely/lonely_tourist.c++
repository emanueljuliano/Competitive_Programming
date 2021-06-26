/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem L. Lonely Mountain                                     */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Gennady Korotkevich                      */
/******************************************************************/

#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 200010;

int x[N], zx[N], y[N], zy[N];

vector < pair < int, pair <double, double> > > ex, ey;

int main() {
  freopen("lonely.in", "r", stdin);
  freopen("lonely.out", "w", stdout);
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, zx + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d %d", y + i, zy + i);
  int hx = 0, hy = 0;
  for (int i = 0; i < n; i++)
    if (zx[i] > hx) hx = zx[i];
  for (int i = 0; i < m; i++)
    if (zy[i] > hy) hy = zy[i];
  if (hx != hy) {
    puts("Invalid plan");
    return 0;
  }
  {
    ex.clear();
    for (int i = 0; i < n - 1; i++) {
      int z1 = zx[i];
      int z2 = zx[i + 1];
      if (z1 > z2) { int tmp = z1; z1 = z2; z2 = tmp; }
      int dx = x[i + 1] - x[i];
      ex.push_back(make_pair(0, make_pair(dx, 0)));
      double dec = (z1 < z2) ? (1.0 * dx / (z2 - z1)) : 0.0;
      ex.push_back(make_pair(z1, make_pair(dec * z1, -dec)));
      ex.push_back(make_pair(z2, make_pair(-dx - dec * z1, dec)));
    }
  }
  {
    ey.clear();
    for (int i = 0; i < m - 1; i++) {
      int z1 = zy[i];
      int z2 = zy[i + 1];
      if (z1 > z2) { int tmp = z1; z1 = z2; z2 = tmp; }
      int dy = y[i + 1] - y[i];
      ey.push_back(make_pair(0, make_pair(dy, 0)));
      double dec = (z1 < z2) ? (1.0 * dy / (z2 - z1)) : 0.0;
      ey.push_back(make_pair(z1, make_pair(dec * z1, -dec)));
      ey.push_back(make_pair(z2, make_pair(-dy - dec * z1, dec)));
    }
  }
  sort(ex.begin(), ex.end());
  sort(ey.begin(), ey.end());
  int nx = ex.size(), ny = ey.size();
  int i = 0, j = 0;
  double kx = 0, bx = 0;
  double ky = 0, by = 0;
  double ans = 0;
  int curz = 0;
  while (i < nx && j < ny) {
    bool to_i = false;
    if (j == ny || (i < nx && ex[i].first < ey[j].first)) {
      to_i = true;
    }
    int nextz = (to_i ? ex[i].first : ey[j].first);
    if (curz < nextz) {
      ans = ans + (kx * ky) * (nextz - curz) + (bx * ky + by * kx) * (1.0 * nextz * nextz - 1.0 * curz * curz) * 0.5
                + (bx * by) * (1.0 * nextz * nextz * nextz - 1.0 * curz * curz * curz) / 3.0;
    }
    curz = nextz;
    if (to_i) {
      kx += ex[i].second.first;
      bx += ex[i].second.second;
      i++;
    } else {
      ky += ey[j].second.first;
      by += ey[j].second.second;
      j++;
    }
  }
  printf("%.17lf\n", ans);
  return 0;
}
