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

int get(int n, int k) {
  int w = n / k;
  return (w + 1) / 2;
}

int main() {
  freopen("garage.in", "r", stdin);
  freopen("garage.out", "w", stdout);
  int W, H, w, h;
  scanf("%d %d %d %d", &W, &H, &w, &h);
  int ans = get(W, w) * get(H, h);
  cout << ans << endl;
  return 0;
}

