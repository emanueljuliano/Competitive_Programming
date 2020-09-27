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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(2*n);
		vector<int> vis(n+10, 0);
		for(auto &i : v) cin >> i;
		vector<int> ans;
		for(int i=0;i <2*n; i++) if(!vis[v[i]]) ans.pb(v[i]), vis[v[i]]=1;
		for(auto x : ans) cout << x << " "; cout << endl;
	}
	
	
	
	exit(0);
}
