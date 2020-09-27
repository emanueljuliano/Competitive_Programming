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
int id[MAX], sz[MAX];

void build(int n){
	for(int i=0;i <=n; i++) id[i]=i, sz[i]=1;
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
	int t; cin >> t;
	while(t--){
	
		int n, m, q; cin >> n >> m >> q;
		build(n);
		for(int i=0; i<m; i++){
			int a, b; cin >> a >> b; a--, b--;
			une(a, b);
		}
		for(int i=0;i <q; i++){
			int a, b; cin >> a >> b; a--, b--;
			if(find(a)==find(b)) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
