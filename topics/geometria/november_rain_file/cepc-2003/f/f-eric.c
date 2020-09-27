/*
  Eric's Own Solution for the problem Football.

  It is based on the fact that the numbers we are asked for (b, w and g) can
  be computed knowing only the number of edges of polygon (n), the number of
  external white angles (ew) and the number of external black angles (eb).
  (An external white/black angle is an angle belonging to a hexagon/pentagon
  which has not been painted green, and its vertex belongs to the boundary
  of the polygon.) In fact, numbers b, w and g can be expressed as linear
  combinations of values n, ew and eb (plus a constant). The numbers ew and
  eb can be calculated easily, using a three state machine to determine types
  of the angles. The solution below does not explicitly calculate the numbers
  ew and eb; instead, it right away calculates the result (b,w,g). The
  connection between (b,w,g) and (n,ew,eb) can be found in two ways:
  
  A) Let m be the number of internal vertices, i. e. vertices whose all
  three faces are white or black. (We call the black-and-white part interior
  and the green part exterior.) Since a pentagon has five black angles,
  a hexagon has 6 black angles, and each internal vertex has one internal
  black angle and two internal white angles, b = (eb + m)/5, w = (ew + 2m)/6.
  Let e be the number of edges such that at least one of the incident faces is
  not green. By counting each edge from both sides, we get 2e = n + 5b + 6w. If
  we use Euler's theorem on the planar graph obtained by taking all of the n+m
  vertices, all of e edges, and all of b+w+1 faces, we get (b+w+1) + (n+m) = 
  e+2, which can be written as (eb+m)/5+(ew+m)/6+n+m+1 = 2+(n+(eb+m)+(ew+2m))/2.
  Using this equation, we can calculate m from n, eb and ew. Knowing m, we can
  calculate b and w. (Of course, g = 32-b-w.)

  B) Denote a black angle by 2A, and the white angle by B. Since one black
  angle and two white angles make a full circle 2pi, we have A + B = pi.
  (Note these are angles of spherical pentagons and hexagons, not planar ones,
  which are equal to 72 and 120 degrees, respectively.) Let F be a function
  on the polygon, defined as F(P) = sum(a_n) - (n-2)pi, where sum(a_n) is the
  sum of all angles of polygon P. F(P) is a linear combination of A and B.
  For example, F(pentagon) = 10A - 3pi = 7A-3B, and F(hexagon) = 6B-4pi =
  2B-4A. It can be shown that F is additive: if the polygon P is a sum of two
  polygons P1 and P2, then F(P) = F(P1) + F(P2). (In fact, if we replaced
  A and B with real measures of these angles, and the football had radius 1,
  then F(P) would be equal to area contained inside P. It works not only for
  polygons drawn on football edges.) Since Eric's polygon E is a sum of 
  b pentagons and w hexagons, we have F(E) = b(7A-3B) + w(2B-4A), and we also
  have F(E) = eb*2A + ew*B + (n-2)(A+B). From these equations, we can see that
  numbers b and w depend on n, eb and ew.
*/

int tab[3][2][4] = {
  {{+10,+15,-25,1},{-10,-15,+25,2}},
  {{+10,+15,-25,0},{-10,-20,+30,1}},
  {{+10,+20,-30,2},{-10,-15,+25,0}}
  };

int main() {
  int state = 0;
  int n, i, k;
  int black = 60, white = 100, green = 160;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &k); k--;
    black += tab[state][k][0];
    white += tab[state][k][1];
    green += tab[state][k][2];
    state =tab[state][k][3];
    }
  printf("%d %d %d\n", black/10, white/10, green/10);
  return 0;
  }
