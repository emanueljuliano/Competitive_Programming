#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MAX = 1e16-10;

int main(){ _

	ll m; cin >> m;

	bool can = 0;
	ll n, s;

	vector<ll> all;
	all.push_back(0);
	ll pref = 0;
	int last = 0;
	for(ll i=1; i < 1e8+10; i++) {
		ll aux = i*i;
		pref += aux;
		last = i;
		if(pref <= 1e16) all.push_back(i*i);		
		else break;
	}
	//cout << last << " " << pow(MAX, 1.0/3) << endl;
	for(ll dim = 3; dim < 55 and !can; dim++) {
		n = dim; 
		pref = 0;
		for(int i=0; i < all.size(); i++) {
			pref += all[i];
			if(pref > MAX) break;
			//else if(pref == m) {can = 1; s = i; break;}
		}
		pref = 0;
		if(!can) {
			cout << last << " " << pow(MAX, 1.0/dim) << endl;
			for(ll i = 1; i <= last; i++) {
				all[i] *= i;
				pref += all[i];
				if(pref > MAX) {last = i; break;}
			}
		}
	} 

	if(can) cout << n << " " << s << endl;
	else cout << "impossible" << endl;

	return 0;
}

