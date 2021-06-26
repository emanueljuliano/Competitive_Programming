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
		vector<vector<int>> v(n+1);
		vector<int> w(n);
		for(int i=1; i<=n; i++){
			int a; cin >> a; a--;
			v[a].pb(i-w[a]);
			w[a] = i;
		}
		for(int i=0;i <n; i++) if(w[i]!=0) v[i].pb(n+1-w[i]);

		int ans = INF;
		for(int i=0;i <n; i++) if(w[i]!=0){
			int at = 0;
			for(auto u : v[i]) if(u!=1) at++;
			ans = min(ans, at);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
