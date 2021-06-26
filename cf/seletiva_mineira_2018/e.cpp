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
const int MAX = 1e5+10;

int id[MAX], sz[MAX], bip[MAX], cor[MAX];
vector<vector<int>> comp(MAX);
void build(int n){
	for(int i=0;i <n; i++) id[i]=i, sz[i]=1, bip[i]=true, cor[i]=0, comp[i].pb(i);
}

int find(int p){
	if(p==id[p]) return p;
	return find(id[p]);
}

void une(int p, int q){
	int fp=find(p), fq=find(q);
	if(fp==fq){
		if(cor[p]==cor[q]) bip[fp] = false;
		return;
	}
	if(sz[fp]>sz[fq]) swap(p, q), swap(fp, fq);
	sz[fq]+=sz[fp], id[fp]=fq;
	if(!bip[fp] or !bip[fq]) {bip[fq]=false; return;}

	if(cor[p]==cor[q]) for(auto u : comp[fp]) cor[u]^=1;
	
	for(auto u : comp[fp]) comp[fq].pb(u);
}

int main(){ _
	int n, q; cin >> n >> q;

	build(n);
	while(q--){
		int f; cin >> f;
		if(f==1){
			int a, b; cin >> a >> b; a--, b--;
			une(a, b);
		}
		else{
			int a; cin >> a; a--;
			if(bip[find(a)]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	
	exit(0);
}
