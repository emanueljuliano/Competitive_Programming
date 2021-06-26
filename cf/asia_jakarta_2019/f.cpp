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

const int MAX = 4e3+10;
int n, subsize[MAX];
vector<int> g[MAX];
int rem[MAX];
ll power[MAX];

const int MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

ll P = uniform(MAX, MOD-1);

void build(){
	power[0] = 1;
	for(int i=1;i <MAX; i++) power[i] = power[i-1]*P%MOD;
}

void dfs(int k, int p=-1){
	subsize[k] = 1;
	for(int i : g[k]) if(!rem[i] and i!=p){
		dfs(i, k);
		subsize[k] += subsize[i];
	}
}

int centroid(int k, int p = -1, int size = -1){
	if(size==-1) size = subsize[k];
	for(int i : g[k]) if(!rem[i] and i!=p) if(subsize[i] > size/2)
		return centroid(i, k, size);
	return k;
}

ii centroids(int k=0){
	dfs(k);
	int i = centroid(k), i2 = i;
	for(int j : g[i]) if(!rem[i] and 2*subsize[j] == subsize[k]) i2 = j;
	return {i, i2};
}

int decomp(int k){
	ii cc = centroids(k);
	if(cc.f != cc.s){
		rem[cc.f] = 1, rem[cc.s] = 1;
		int h1 = decomp(cc.f);
		int h2 = decomp(cc.s);
		
		return (h1+h2)%MOD;
	}
	else{
		rem[cc.f] = 1;
		vector<int> hs;
		for(auto u : g[cc.f]) if(!rem[u]) hs.pb(decomp(u));
		sort(hs.begin(), hs.end());
		int at = 0;
		for(int i=0;i <hs.size(); i++) at = (at+hs[i]*power[i])%MOD;
		if(hs.size()==0) return 3;
		return at;
	}
}

int main(){ _
	cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}

	ii cs = centroids();
	if(cs.f != cs.s){
		cout << -1 << endl;
		return 0;
	}
	
	build();
	rem[cs.f]=1;
	vector<int> hashs;
	for(auto u : g[cs.f]) hashs.pb(decomp(u));
	sort(hashs.begin(), hashs.end());
	if(hashs[0] == hashs.back()) cout << hashs.size() << endl;
	else cout << -1 << endl;
	
	
	exit(0);
}
