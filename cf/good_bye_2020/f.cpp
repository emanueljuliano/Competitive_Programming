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

const int MOD = 1e9+7;

const int MAX = 5e5+10;
int id[MAX], sz[MAX], complete[MAX];
void build(int m){
	for(int i=0;i <=m; i++) id[i]=i, sz[i]=1;
}
int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}
void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
	complete[q] |= complete[p];
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<ii> v;
	for(int i=0;i <n; i++){
		int k; cin >> k;
		if(k==1) {
			int a; cin >> a; a--;
			v.pb({a, -1});
		}
		else{
			int a, b; cin >> a >> b; a--, b--;
			v.pb({a, b});
		}
	}

	vector<int> ans;
	build(m);
	for(int i=0;i <n; i++){
		int a=v[i].f, b=v[i].s;
		if(b==-1){
			a = find(a);
			if(!complete[a]) complete[a]=1, ans.pb(i);
		}
		else{
			a = find(a), b = find(b);
			if(a != b and (!complete[a] or !complete[b])) une(a, b), ans.pb(i);
		}
	}

	ll tot = 1;
	for(int i=0;i <(int)ans.size(); i++) tot = (tot*2)%MOD;
	
	cout << tot << " " << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for(auto u : ans) cout << u+1 << " ";
	cout << endl;

	exit(0);
}
