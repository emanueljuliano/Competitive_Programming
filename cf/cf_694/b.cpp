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

const int MAX = 1e6+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

int sz[MAX], id[MAX];

void build(int n){
	for(int i=0;i <=n; i++) sz[i]=1, id[i]=i;
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
}

int main(){ _
	crivo(MAX-2);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;	
		build(n);
		map<vector<int>, int> mp;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			vector<int> val;
			val.pb(1);
			if(a!=1){
				vector<int> f;
				fact(f, a);
				sort(f.begin(), f.end());
				for(auto u : f) {
					if(u==val.back()) val.pop_back();
					else val.pb(u);
				}
				//cout << "atual " << a << " = ";
				//for(auto u : val) cout << u << " ";
				//cout << endl;
			}
			if(mp.count(val)) une(i, mp[val]);
			else mp[val] = i;
		}
		int ans0 = 1;
		for(int i=0;i <n; i++) ans0 = max(ans0, sz[find(i)]);
		
		int ans1 = ans0;
		vector<int> one = {1};
		vector<int> to_une;
		if(mp.count(one)) to_une.pb(mp[one]);
		for(int i=0;i <n; i++) if(sz[find(i)]%2==0) to_une.pb(i);
		for(auto u : to_une) une(u, to_une[0]);
		
		for(int i=0;i <n; i++) ans1 = max(ans1, sz[find(i)]);

		int q; cin >> q;
		while(q--){
			ll w; cin >> w;
			if(w==0) cout << ans0 << endl;
			else cout << ans1 << endl;
		}
	}
	
	
	
	exit(0);
}
