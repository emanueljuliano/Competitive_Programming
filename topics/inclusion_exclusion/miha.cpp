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
const int MAX = 3e5;
const ll MAX2 = 4e10;

int pri[MAX];
void crivo(){
	for(int i=2; i<MAX; i++) pri[i] = 1; 
	for(ll i=2; i<MAX; i++)
		if(pri[i]){
			int p = i;
			while(p+i<MAX){
				p+=i;
				pri[p] = 0;
			}
		}
}
vector<vector<ll>> v(10);

ll qp(ll n){
	ll ret = 0;
	for(int i=1; !v[i].empty(); i++){
		for(int j=0; j<v[i].size(); j++){
			if(i%2) ret+= n/v[i][j];
			else ret -= n/v[i][j];
		}	
	}
	return ret;
}

int main(){ _
	crivo();

	v[0].pb(1);
	for(ll i=2; i*i<=MAX2; i++) if(pri[i]) {
		ll a = i*i;
		for(int j=1; !v[j-1].empty(); j++){
			if(MAX2/v[j-1][0] < a) break;
			for(int l=0; l<v[j-1].size(); l++){
				ll x = v[j-1][l];
				if(MAX2/x < a or x%a==0) continue;
				x*=a;
				v[j].pb(x);
			}
		}
	}

/*	for(int i=0; i<10; i++){
		cout << "v[" << i<< "] size " << v[i].size() << endl;
		for(int j=0; j<min(10, (int)v[i].size()); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
*/
	int t; cin >> t;	
	while(t--){
		ll n; cin >> n;
		ll at = 0;
		while(true){
			ll d = qp(n);
			if(d-at == 0) break;
			n += d-at;
			at = d;
		}	
		cout << n << endl;
	}
	
	
	exit(0);
}
