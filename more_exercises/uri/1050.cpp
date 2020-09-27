#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	if(n==61) cout << "Brasilia" << endl;
	else if(n==71) cout << "Salvador" << endl;
	else if(n==11) cout << "Sao Paulo" << endl;
	else if(n==21) cout << "Rio de Janeiro" <<endl;
	else if(n==32) cout << "Juiz de Fora" << endl;
	else if(n==19) cout << "Campinas" << endl;
	else if(n==27) cout << "Vitoria" << endl;
	else if(n==31) cout << "Belo Horizonte" << endl;
	else cout << "DDD nao cadastrado" << endl;
	
	exit(0);
}
