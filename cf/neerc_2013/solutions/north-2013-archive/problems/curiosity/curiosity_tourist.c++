/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem C. Correcting Curiosity                                */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Maxim Buzdalov                           */
/* Test set              Maxim Buzdalov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Gennady Korotkevich                      */
/******************************************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long co = 237042017;
const int md1 = 1000000007;
const int md2 = 1000000047;

const int N = 4100;

char a[N], b[N];
int fb[N][N], fab[N][N];
int ha[N], hb[N], pwa[N], pwb[N];

int main() {
  freopen("curiosity.in", "r", stdin);
  freopen("curiosity.out", "w", stdout);
  gets(a);
  gets(b);
  int n = strlen(a);
  int m = strlen(b);
  ha[0] = hb[0] = 0;
  for (int i = 0; i < n; i++) ha[i + 1] = (1LL * ha[i] * co + a[i]) % md1;
  for (int i = 0; i < n; i++) hb[i + 1] = (1LL * hb[i] * co + a[i]) % md2;
  pwa[0] = pwb[0] = 1;
  for (int i = 1; i <= n; i++) {
    pwa[i] = 1LL * pwa[i - 1] * co % md1;
    pwb[i] = 1LL * pwb[i - 1] * co % md2;
  }
  for (int i = n; i >= 0; i--)
    for (int j = m; j >= 0; j--)
      if (i == n || j == m) fab[i][j] = 0; else
      if (a[i] == b[j]) fab[i][j] = fab[i + 1][j + 1] + 1;
      else fab[i][j] = 0;
  for (int i = m; i >= 0; i--)
    for (int j = m; j >= 0; j--)
      if (i == m || j == m) fb[i][j] = 0; else
      if (b[i] == b[j]) fb[i][j] = fb[i + 1][j + 1] + 1;
      else fb[i][j] = 0;
  int alen = 123456, alenb = 123456, astart = 0;
  for (int len = 1; len <= n; len++) {
    vector < pair <long long, int> > h;
    for (int p = 0; p <= n - len; p++) {
      int hash1 = (ha[p + len] - 1LL * ha[p] * pwa[len]) % md1;
      if (hash1 < 0) hash1 += md1;
      int hash2 = (hb[p + len] - 1LL * hb[p] * pwb[len]) % md2;
      if (hash2 < 0) hash2 += md2;
      h.push_back(make_pair((((long long)hash1) << 32) + hash2, p));
    }
    sort(h.begin(), h.end());
    int sz = h.size();
    int beg = 0;
    while (beg < sz) {
      int end = beg;
      while (end + 1 < sz && h[end + 1].first == h[beg].first) end++;
      vector <int> used;
      int last = -1;
      for (int j = beg; j <= end; j++) {
        if (h[j].second > last) {
          used.push_back(h[j].second);
          last = h[j].second + len - 1;
        }
      }
      int cnt = used.size();
      if ((m - n) % cnt == 0) {
        int diff = (m - n) / cnt;
        int lenb = len + diff;
        if (lenb >= 0 && lenb <= m) {
          int first = used[0];
          bool ok = true;
          for (int j = 1; j < cnt; j++) {
            int cur = used[j] + diff * j;
            if (fb[first][cur] < lenb) {
              ok = false;
              break;
            }
          }
          if (ok) {
            if (fab[0][0] >= first) {
              used.push_back(n);
              for (int j = 0; j < cnt; j++) {
                int cur = used[j] + diff * j;
                if (fab[used[j] + len][cur + lenb] < used[j + 1] - used[j] - len) {
                  ok = false;
                  break;
                }
              }
              if (ok) {
                if (len + lenb < alen + alenb) {
                  alen = len;
                  alenb = lenb;
                  astart = used[0];
                }
              }
            }
          }
        }
      }
      beg = end + 1;
    }
  }
  printf("s/");
  for (int j = astart; j <= astart + alen - 1; j++) putchar(a[j]);
  putchar('/');
  for (int j = astart; j <= astart + alenb - 1; j++) putchar(b[j]);
  printf("/g\n");
  return 0;
}
