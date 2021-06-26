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

int id[int(2e5+10)];
void build(int n){
	for(int i=0; i<n; i++) id[i] = i;
}

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p), q = find(q);
	id[p] = q;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;

		vector<pair<int, ii>> eg;
		for(int i=0;i <m; i++){
			int a, b, c; cin >> a >> b >> c; a--, b--;
			eg.pb({c, {a, b}});
		}

		sort(eg.begin(), eg.end());
		build(n);
		ll ans = 0;
		for(int i=0;i <m; i++){
			int c = eg[i].f, a = eg[i].s.f, b = eg[i].s.s;
			if(find(a) != find(b)){
				une(a, b);
				if(c>k) ans += c-k;
			}
		}

		if(ans) cout << ans << endl;
		else{
			ans = INF;
			for(auto [c, p] : eg) ans = min(ans, (ll)abs(k-c));
			cout << ans << endl;
		}
	}
	
	
	exit(0);
}
