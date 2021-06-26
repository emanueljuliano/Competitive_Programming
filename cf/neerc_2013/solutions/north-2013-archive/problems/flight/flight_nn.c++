/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem F. Flight Boarding Optimization                        */
/*                                                                */
/* Original idea         Pavel Mavrin                             */
/* Problem statement     Pavel Mavrin                             */
/* Test set              Pavel Mavrin                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>

const int INF = 1 << 30;
int d[1234][1234];
int dp[1234], ne[1234], a[1234];

int main() {
  freopen("flight.in", "r", stdin);
  freopen("flight.out", "w", stdout);
  int n, s, k;
  scanf("%d%d%d", &n, &s, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    --a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] >= a[j]) continue;
      d[a[i]][a[j]]++;
    }
  }
  for (int i = s - 1; i > 0; i--) {
    for (int j = 0; j < s; j++) {
      d[i - 1][j] += d[i][j];
    }
  }
  for (int i = 0; i < s; i++) {
    for (int j = 1; j < s; j++) {
      d[i][j] += d[i][j - 1];
    }
  }
  for (int i = 0; i <= s; i++) {
    dp[i] = INF;
  }
  dp[0] = 0;
  for (int st = 0; st < k; st++) {
    for (int i = 0; i <= s; i++) ne[i] = INF;
    for (int i = 0; i < s; i++) {
      for (int j = i; j < s; j++) {
        if (ne[j + 1] > dp[i] + d[i][j]) {
          ne[j + 1] = dp[i] + d[i][j];
        }
      }
    }
    for (int i = 0; i <= s; i++) dp[i] = ne[i];
  }
  printf("%d\n", dp[s]);
}
