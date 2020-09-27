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
	vector<double> v;
	for(int i=0;i <3; i++) {double a; cin >> a; v.pb(a);}
	sort(v.begin(), v.end());
	double a, b, c; a= v[2], b=v[1], c=v[0];
	if(a>=b+c) return cout << "NAO FORMA TRIANGULO" << endl, 0;
	if(a*a == b*b + c*c) cout << "TRIANGULO RETANGULO"  << endl;
	else if(a*a > b*b + c*c) cout << "TRIANGULO OBTUSANGULO" << endl;
	else if( a*a < b*b + c*c) cout << "TRIANGULO ACUTANGULO" << endl;
	if(a==b and a==c) cout << "TRIANGULO EQUILATERO"  << endl;
	else if(a==b or a==c or b==c) cout << "TRIANGULO ISOSCELES" << endl;
	
	
	
	exit(0);
}
