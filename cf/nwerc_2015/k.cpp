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
const ll MAX = 1e18;

int main(){ _
	int r, s, m, d, n; cin >> r >> s >> m >> d >> n;
	vector<int> b(r);
	for(auto &i : b) cin >> i;
	
	vector<vector<int>> v(s+m+d);
	for(int i=0;i <s+m+d; i++){
		int k; cin >> k;
		v[i].resize(k);
		for(auto &j : v[i]) cin >> j, j--;
	}

	set<ii> st;
	for(int i=0;i <n; i++){
		int x, y; cin >> x >> y; x--, y--;
		if(x>y) swap(x, y);
		st.insert({x, y});
	}

	vector<int> vis(r);
	ll ans = 0;
	auto pode = [&](ll x, ll y){
		if(x>(MAX + y -1)/y) return false;
		x*=y;
		if(x>MAX) return false;
		return true;
	};

	bool too_many = false;
	for(int i=0;i <s; i++){
		for(int j=s; j<s+m; j++){
			for(int k=s+m; k<s+m+d; k++){
				if(st.count({i, j}) or st.count({i, k}) or st.count({j, k})) continue;
				
				ll cur = 1;
				for(auto a : v[i]) if(!vis[a]){
					vis[a]=1;
					// cur * b[a] > 1e18)
					if(!pode(cur, b[a])) too_many = true;
					else cur*=b[a];
				}
				for(auto a : v[j]) if(!vis[a]){
					vis[a]=1;
					if(!pode(cur, b[a])) too_many = true;
					else cur*=b[a];
				}
				for(auto a : v[k]) if(!vis[a]){
					vis[a]=1;
					if(!pode(cur, b[a])) too_many = true;
					else cur*=b[a];
				}
				ans += cur;
				if(ans>MAX) too_many = true;
				for(auto a : v[i]) vis[a] = 0;
				for(auto a : v[j]) vis[a] = 0;
				for(auto a : v[k]) vis[a] = 0;
			}
		}
	}
	if(too_many) cout << "too many" << endl;
	else cout << ans << endl;
	
	exit(0);
}
