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
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 33333;
string s[N], s1[N], s2[N];
int ne[N], he[N], p1[N], p2[N], cc, was[N], ga[N], ac[N], ss[N], ff[N];

bool dfs(int v) {
  if (was[v] == cc) return false;
  was[v] = cc;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (p2[ff[e]] < 0 || dfs(p2[ff[e]])) {
      p1[v] = ff[e];
      p2[ff[e]] = v;
      return true;
    }
  }
  return false;
}

int main() {
  freopen("heavy.in", "r", stdin);
  freopen("heavy.out", "w", stdout);
  int n, k;
  scanf("%d%d", &n, &k);  
  for (int i = 0; i < n; i++) {
    cin >> s[i];    
    s1[i] = s[i].substr(0, k);
    s2[i] = s[i].substr(s[i].length() - k, k);
  }
  std::sort(s1, s1 + n);
  int m1 = unique(s1, s1 + n) - s1;
  std::sort(s2, s2 + n);
  int m2 = unique(s2, s2 + n) - s2;
  for (int i = 0; i < n; i++) {
    {
      int id = lower_bound(s1, s1 + m1, s[i].substr(0, k)) - s1;
      ss[i] = id;
    }
    {
      int id = lower_bound(s2, s2 + m2, s[i].substr(s[i].length() - k, k)) - s2;
      ff[i] = id;
    }
  }
  for (int i = 0; i < m1; i++) he[i] = -1;
  for (int i = 0; i < n; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  cc = 0;
  for (int i = 0; i < m1; i++) p1[i] = -1;
  for (int i = 0; i < m2; i++) p2[i] = -1;
  int ans = 0;
  for (int i = 0; i < m1; i++) {
    for (int e = he[i]; e >= 0; e = ne[e]) {
      if (p2[ff[e]] < 0) {
        p2[ff[e]] = i;
        p1[i] = ff[e];
        ++ans;
        break;
      }
    }
  }
  for (int i = 0; i < m1; i++) {
    if (p1[i] >= 0) continue;
    ++cc;
    if (dfs(i)) {
      ++ans;
    }
  }
  ++cc;
  printf("%d\n", ans);
  for (int i = 0; i < m1; i++) {
    if (p1[i] < 0) dfs(i);
  }
  for (int i = 0; i < n; i++) ga[i] = false;
  for (int i = 0; i < m1; i++) {
    if (was[i] != cc) {
      int cn = 0;
      for (int e = he[i]; e >= 0; e = ne[e]) {
        if (!ga[e]) {
          ga[e] = true;
          ac[cn++] = e;
        }
      }
      printf("%d", cn);
      for (int j = 0; j < cn; j++) {
        printf(" %d", ac[j] + 1);
      }
      puts("");
    }
  }
  for (int i = 0; i < m2; i++) he[i] = -1;
  for (int i = 0; i < n; i++) {
    ne[i] = he[ff[i]];
    he[ff[i]] = i;
  }
  for (int i = 0; i < m2; i++) {
    if (p2[i] >= 0 && was[p2[i]] == cc) {
      int cn = 0;
      for (int e = he[i]; e >= 0; e = ne[e]) {
        if (!ga[e]) {
          ga[e] = true;
          ac[cn++] = e;
        }
      }
      printf("%d", cn);
      for (int j = 0; j < cn; j++) printf(" %d", ac[j] + 1);
      puts("");
    }
  }
}

