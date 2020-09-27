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
	double a; cin >> a;
	cout << setprecision(2) << fixed; 
	if(a<=2000) return cout << "Isento" << endl, 0;
	double tot=0;
	a -= 2000;
	tot += min(a, 1000.0)*0.08;
	a -= 1000;
	if(a>0) tot += min(a, 1500.0)*0.18;
	a -= 1500;
	if(a>0) tot += a*0.28;

	cout <<"R$ " << tot<< endl;
	
	
	
	exit(0);
}
