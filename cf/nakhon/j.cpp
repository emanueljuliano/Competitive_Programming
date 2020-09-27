#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;

/*A gente quer saber o valor explicito de (x + y)^-3 + x^-3 sem ter q efetivamente fazer a subtração, pq isso vai dar erro por razões de epsilon da máquina. Então a gente quer representar ele como a soma de números pequenos e não como subtração de números grandes

  Então vamos fazer assim, representa o primeiro termo como a+b e o segundo como a, então a gente quer saber a+b-a = b

  A gente sabe que (a+b)³ = x + y e que a³ = x
  logo,
	(a+b)³ = a³ + 3a²b + 3ab² + b³ = x + y
	x + 3*x^(2/3)*b + 3*x^(1/3)*b² + b³ = x + y
	3*x^(2/3)*b + 3*x^(1/3)*b² + b³ = 10^-15 
	//b é muito pequeno então só o primeiro termo importa
	3*x^(2/3)*b = 10^-15
	b = 10^-15/(3*x^(2/3))
*/

int main(){// _
	while(true){
		int l, r; scanf("%d %d", &l, &r);
		if(l==0) break;
		ld ans = 0.0;
		for(l; l<=r; l++){
			ans += 1/pow((ld)l, 2.0/3.0);
		}
		ans /=3.0;
		ans *= 1e-15;
		printf("%.5E\n", ans);
	}



	exit(0);
}
