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
/* Author                Oleg Davydov                             */
/******************************************************************/

#include <algorithm>
#include <fstream>

using namespace std;

int main() {
  ifstream in("garage.in");
  ofstream out("garage.out");
  long long W, H, w, h;
  in >> W >> H >> w >> h;
  W += w;
  H += h;
  w = 2 * w;
  h = 2 * h;
  out << (W / w) * (H / h) << endl;
  return 0;
}


