/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem G. Garage                                              */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Oleg Davydov                             */
/* Test set              Oleg Davydov                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>

int main() {
  freopen("garage.in", "r", stdin);
  freopen("garage.out", "w", stdout);
  int w, h, a, b;
  scanf("%d%d%d%d", &w, &h, &a, &b);
  int c = w / a;
  int d = h / b;
  c = (c + 1) / 2;
  d = (d + 1) / 2;
  printf("%d\n", c * d);
}
