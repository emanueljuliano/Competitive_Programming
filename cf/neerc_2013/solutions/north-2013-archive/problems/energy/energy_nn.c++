/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem E. Energy Tycoon                                       */
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

int main() {  
  freopen("energy.in", "r", stdin);
  freopen("energy.out", "w", stdout);
  int n;
  scanf("%d", &n);
  int c = getchar();
  while (c <= 32) c = getchar();
  long long ans = 0;
  int ones = 0;
  int twos = 0;
  while (c > 32) {
    if (c == '1') {
      if (n - ones - 2 * twos > 0) {
        ++ones;
      } else if (twos > 0) {
        --twos;
        ++ones;
      }
    } else {
      if (n - ones - 2 * twos >= 2) {
        ++twos;
      }      
    }
    ans += ones + twos;
    c = getchar();
  }
  printf("%I64d\n", ans);
}
