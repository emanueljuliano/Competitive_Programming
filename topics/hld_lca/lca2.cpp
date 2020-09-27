#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e3+10;

vector<vector<int>> g(MAX);
int pos[MAX], h[MAX], sz[MAX];
int pai[MAX], t=0;

void build(int k, int p=-1, int f=1){
	pos[k] = t++; sz[k] = 1;
	for(int& i : g[k]) if(i!=p){
		pai[i] = k;
		h[i] = (i==g[k][0] ? h[k] : i);
		build(i, k, f); sz[k] += sz[i];

		if(sz[i] > sz[g[k][0]] or g[k][0]==p) swap(i, g[k][0]);
	}
	if(p*f==-1) t=0, h[k]=k, build(k, -1, 0);
}

int lca(int a, int b){
	if(pos[a]<pos[b]) swap(a, b);
	return h[a] == h[b] ? b : lca(pai[h[a]], b);
}

int main(){ _


	exit(0);
}
