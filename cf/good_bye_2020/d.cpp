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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> w(n);
		for(auto &i : w) cin >> i;
		ll ans = 0;
		for(auto u : w) ans += u;
		
		vector<ii> v;
		vector<int> dg(n);
		for(int i=0;i <n-1; i++){
			int a, b; cin >> a >> b; a--, b--;
			dg[a]++, dg[b]++;
		}
		for(int i=0;i <n; i++){
			if(dg[i]>1) v.pb({w[i], dg[i]-1});
		}
		sort(v.begin(), v.end(), greater<>());
		cout << ans << " ";
		int it = 1;
		for(auto [u, d] : v){
			while(d){
				ans += u;
				cout << ans << " ";
				it++, d--;
				if(it>=n-1) break;
			}
			if(it>=n-1) break;
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
