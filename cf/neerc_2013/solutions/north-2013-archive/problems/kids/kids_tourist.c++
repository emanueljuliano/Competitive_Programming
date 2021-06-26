/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem K. Kids in a Friendly Class                            */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Mikhail Dvorkin                          */
/* Test set              Mikhail Dvorkin                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Gennady Korotkevich                      */
/******************************************************************/

#include <stdio.h>
#include <set>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  freopen("kids.in", "r", stdin);
  freopen("kids.out", "w", stdout);
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int am = 12345, an = 12345;
  for (int m = a + 1; m <= 4 * 52 * 52; m++)
    for (int n = d + 1; n <= 4 * 52 * 52; n++)
      if (m * b == n * c)
        if ((m * a) % 2 == 0 && (n * d) % 2 == 0)
          if (m >= c && n >= b)
            if (m + n < am + an) {
              am = m;
              an = n;
            }
  int m = am, n = an;
  printf("%d %d\n", m, n);
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= i + (a / 2); j++) printf("%d %d\n", i, (j - 1) % m + 1);
  if (a % 2 == 1) {
    for (int i = 1; i <= m / 2; i++) printf("%d %d\n", i, m / 2 + i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= i + (d / 2); j++) printf("%d %d\n", m + i, m + (j - 1) % n + 1);
  if (d % 2 == 1) {
    for (int i = 1; i <= n / 2; i++) printf("%d %d\n", m + i, m + n / 2 + i);
  }
  int id = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= b; j++) {
      id++;
      if (id > n) id = 1;
      printf("%d %d\n", i, m + id);
    }
  return 0;
}

