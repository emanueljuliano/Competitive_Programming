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

const int MAX = 1e5+10;
int id[MAX], sz[MAX], vis[MAX];

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}
void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	sz[q] += sz[p];
	id[p] = q;
}
void build(){
	for(int i=0;i <MAX-5; i++){
		id[i] = i; sz[i] =1; vis[i] = 0;
	}
}

int main(){ _
	int n, m , k; cin >> n >> m >> k;
	int at = 0;
	map<string, int> mp;
	build();
	for(int i=0;i <m; i++){
		string s, t; cin >> s >> t;
		if(!mp.count(s)) mp[s] = at++;
		if(!mp.count(t)) mp[t] = at++;
		une(mp[s], mp[t]);
	}
	vector<int> comp;
	for(int i=0;i <n; i++){
		if(vis[find(i)]) continue;
		vis[find(i)] = 1;
		comp.pb(sz[find(i)]);
	}
	sort(comp.begin(), comp.end(), greater<>());
	int ans = 0;
	for(int i=0;i <min(k, (int)comp.size()); i++){
		ans += comp[i];
	}
	cout << ans << endl;
	
	exit(0);
}
