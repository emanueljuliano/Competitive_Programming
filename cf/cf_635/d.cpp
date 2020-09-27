#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back
#define sq(x) ((ll)(x)*(x))

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll form(ll x, ll y, ll z){
	return ll(sq(x-y) + sq(y-z) + sq(z-x));
}

int main(){ _
	int t;cin >> t;
	while(t--){
		int nr, ng, nb; cin >> nr >> ng >> nb;
		vector<ll> r, g, b;
		
		ll ans = LINF;
		for(int i=0; i<nr; i++){ll a; cin >> a; r.pb(a);}
		for(int i=0; i<ng; i++){ll a; cin >> a; g.pb(a);}
		for(int i=0; i<nb; i++){ll a; cin >> a; b.pb(a);}
	
		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());
		
		int it1=0, it2=0, it3=0;
		//cout << "TES" << endl;
		
		while(true){
			
			ll x = r[it1];
			ll y = g[it2];
			ll z=b[it3];
			ans = min(ans, form(x, y, z));
			
			ll x1=x, y1=y, z1=z;	
			if(it1<nr-1) x1 = r[it1+1];
			if(it2<ng-1) y1 = g[it2+1];
			if(it3<nb-1) z1 = b[it3+1];

			ll a1=form(x1, y, z), a2=form(x, y1, z), a3=form(x, y, z1);
			ans = min(ans, min(a1, min(a2, a3)));

		//	cout << "A's = " << a1 << " "<< a2 << " " << a3 << endl;
		//	cout << "Iteradores = ";
		//	cout << it1 << " "<< it2 << " " << it3 << endl;
			
			if(a1<ans) it1++;
			else if(a2<ans) it2++;
			else if(a3<ans) it3++;
			else{
				if(a1<=a2 and a1<=a3 and it1<nr-1) it1++;
				else if(a2<=a3 and it2<ng-1) it2++;
				else if(it3<nb-1) it3++;
				else if(it2<ng-1) it2++;
				else if(it1<nr-1) it1++;
				else break;
			}
		}
		
		cout << ans << endl;
		//cout << endl;
	}
	
	
	
	exit(0);
}
