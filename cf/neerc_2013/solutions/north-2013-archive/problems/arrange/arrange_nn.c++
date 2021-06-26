/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem A. Arrangement of Contest                              */
/*                                                                */
/* Original idea         Egor Kulikov                             */
/* Problem statement     Egor Kulikov                             */
/* Test set              Egor Kulikov                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

#include <cstdio>
#include <iostream>

using namespace std;

bool can[323];

int main() {
  freopen("arrange.in", "r", stdin);
  freopen("arrange.out", "w", stdout);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    can[s[0]] = true;
  }
  int i = 'A';
  while (can[i]) ++i;
  printf("%d\n", i - 'A');
}
