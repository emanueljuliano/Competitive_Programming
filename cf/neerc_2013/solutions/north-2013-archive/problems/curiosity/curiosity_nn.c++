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
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int P = 239;

const long long M1 = 1000000007;
const long long M2 = 1000000009;
const int N = 2222;

long long h1[N], h2[N], hs1[N], hs2[N], ht1[N], ht2[N], pow1[N], pow2[N];
int id[N];

int gethash1(long long * h, int l, int r) {
  long long ret = h[r - 1];
  if (l > 0) {
    ret = (ret + M1 * M1 - h[l - 1] * pow1[r - l]) % M1;
  }
  return ret;
}

int gethash2(long long * h, int l, int r) {
  long long ret = h[r - 1];
  if (l > 0) {
    ret = (ret + M2 * M2 - h[l - 1] * pow2[r - l]) % M2;
  }
  return ret;
}

bool comph(int i, int j) {
  if (h1[i] != h1[j]) return h1[i] < h1[j];
  if (h2[i] != h2[j]) return h2[i] < h2[j];
  return i < j;
}

int main() {
  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < N; i++) {
    pow1[i] = pow1[i - 1] * P % M1;
    pow2[i] = pow2[i - 1] * P % M2;
  }
  freopen("curiosity.in", "r", stdin);
  freopen("curiosity.out", "w", stdout);
  string s, t;
  getline(cin, s);
  getline(cin, t);
  int n = s.length();
  int m = t.length();
  for (int i = 0; i < n; i++) {
    hs1[i] = ((i > 0 ? hs1[i - 1] : 0LL) * P + s[i]) % M1;    
    hs2[i] = ((i > 0 ? hs2[i - 1] : 0LL) * P + s[i]) % M2;
  }
  for (int i = 0; i < m; i++) {
    ht1[i] = ((i > 0 ? ht1[i - 1] : 0LL) * P + t[i]) % M1;
    ht2[i] = ((i > 0 ? ht2[i - 1] : 0LL) * P + t[i]) % M2;
  }
  int ans1 = 1 << 20;
  int ans2 = 1 << 20;
  int ansI = -1;
  for (int len = 1; len <= n; len++) {
    if (len >= ans1 + ans2) 
      continue;
    int cn = 0;
    for (int i = 0; i + len <= n; i++) {
      h1[i] = gethash1(hs1, i, i + len);
      h2[i] = gethash2(hs2, i, i + len);
      id[i] = i;
      ++cn;
    }
    std::sort(id, id + cn, comph);
    for (int i = 0; i < cn; ) {
      int j = i;
      while (j < cn && h1[id[i]] == h1[id[j]] 
            && h2[id[i]] == h2[id[j]]) {
        ++j;
      }
      int lst = 0;
      int cc = 0;
      for (int k = i; k < j; k++) {
        if (lst > id[k]) continue;
        ++cc;
        lst = id[k] + len;
      }
      int lenLeft = n - cc * len;
      if ((m - lenLeft) % cc != 0 && m >= lenLeft) {
        i = j;
        continue;
      }
      int len2 = (m - lenLeft) / cc;
      if (len2 < 0 || len + len2 >= ans1 + ans2) {
        i = j;
        continue;
      }
      int H1 = gethash1(ht1, id[i], id[i] + len2);
      int H2 = gethash2(ht2, id[i], id[i] + len2);
      lst = 0;
      int lst2 = 0;
      bool ok = true;
      for (int k = i; k < j; k++) {
        if (lst > id[k]) continue;
        int leq = id[k] - lst;
        if (gethash1(hs1, lst, id[k]) != gethash1(ht1, lst2, lst2 + leq) 
            || gethash2(hs2, lst, id[k]) != gethash2(ht2, lst2, lst2 + leq)) {
          ok = false;
          break;
        }
        lst2 += leq;
        if (gethash1(ht1, lst2, lst2 + len2) != H1 || gethash2(ht2, lst2, lst2 + len2) != H2) {
          ok = false;
          break;
        }
        lst2 += len2;
        lst += leq;
        lst += len;
      }
      if (gethash1(hs1, lst, n) != gethash1(ht1, lst2, m) || gethash2(hs2, lst, n) != gethash2(ht2, lst2, m)) {
        ok = false;
      }
      if (ok) {
        ans1 = len;
        ans2 = len2;
        ansI = id[i];
      }
      i = j;
    }
  }
//  printf("%d %d %d\n", ans1, ans2, ansI);
  cout << "s/" << s.substr(ansI, ans1) << "/" << t.substr(ansI, ans2) << "/g";
}

