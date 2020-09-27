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
	double x; cin >> x;
	double w = x;
	int d;
	cout << setprecision(2) << fixed;
	if(x<=400) x *= 1.15, d=15;
	else if(x<=800) x*=1.12, d=12;
	else if(x<=1200) x*= 1.1, d=10;
	else if(x<=2000) x*=1.07, d=7;
	else x*= 1.04, d=4;
	cout << "Novo salario: " << x << endl;
	cout << "Reajuste ganho: " << x-w << endl;
	cout << "Em percentual: " << d << " %" << endl;
	
	
	exit(0);
}
