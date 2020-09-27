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

vector<int> primes;
void criv(int n){
	vector<int> v(n, 1);
	v[0] = 0;
	v[1] = 0;
	primes.pb(1);
	for(int i=2; i<=n; i++){
		if(v[i]){ 
			primes.pb(i);
			int p = i;
			while(p+i<=n){
				p+=i;
				v[p]=0;
			}
		}
	}
}

int main(){ _
	criv((int)1e6+10);
	int t; cin >> t;
	int cas = 0;
	vector<int> st;
	vector<vector<ll>> v(15);
	while(t--){
		cas++;
		st.clear();
		for(int i=0; i<15; i++) v[i].clear();

		v[0].pb(1);

		ll n, k; cin>> n >> k;
		ll ans = n;
		
		for(int i=0; i<k; i++){	
			ll a; cin >> a;
			//if(st.count(a)){i--, k--; continue;}
			st.pb(a);
		
			for(int j=0; j<=i; j++){
				for(int l=0; l<v[j].size(); l++){
					ll p = v[j][l]*a;
					if(j%2==0) ans -= n/(p);
					else ans += n/(p);
				}
				if(j==0) continue;
				for(int l=0; l<v[j-1].size(); l++){
					ll p = v[j-1][l];
					if(p%a==0) continue;
					p*=a;
					v[j].pb(p);
				}
			}
			v[i+1].pb(a*v[i][0]);
		}
		
	/*	for(int i=0; i<=k; i++){
			for(int j=0; j<v[i].size(); j++)
				cout << v[i][j] << " ";
			cout << endl;
		}
	*/
		for(int i=0; i<primes.size(); i++){
			if(n<primes[i]) break;
			//if(!st.count(primes[i])) 
			ans--;
		}
		for(auto i : st){
			if(i<=n) ans++;
		}
		ans = max((int)ans, 0);
		cout << "Case " << cas << ": " << ans << endl;
	}
	
	
	
	exit(0);
}
