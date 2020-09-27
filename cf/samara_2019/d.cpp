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

const int MAX = 2e5+10;
const int MAX2 = ceil(log2(MAX));

vector<vector<int> > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];

void dfs(int k) {
	in[k] = p++;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (in[g[k][i]] == -1) {
			pai[0][g[k][i]] = k;
			dfs(g[k][i]);
		}
	out[k] = p++;
}

void build(int raiz) {
	for (int i = 0; i < n; i++) pai[0][i] = i;
	p = 0, memset(in, -1, sizeof in);
	dfs(raiz);

	// pd dos pais
	for (int k = 1; k < MAX2; k++) for (int i = 0; i < n; i++)
		pai[k][i] = pai[k - 1][pai[k - 1][i]];
}

bool anc(int a, int b) { // se a eh ancestral de b
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b) {
	if (anc(a, b)) return a;
	if (anc(b, a)) return b;

	// sobe a
	for (int k = MAX2 - 1; k >= 0; k--)
		if (!anc(pai[k][a], b)) a = pai[k][a];

	return pai[0][a];
}

int main(){ _
	cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	build(0);
	int q; cin >> q;
	while(q--){
		int r, b; cin >> r >> b;
		vector<int> red, blue;
		for(int i=0;i <r; i++){
			int a; cin >> a; a--;red.pb(a);
		}
		for(int i=0;i <b; i++) {int a; cin >> a; a--; blue.pb(a);}
		int lr, lb;
		lr = red[0]; lb=blue[0];
		for(int i=1;i <r; i++) lr = lca(red[i], lr);
		for(int i=1;i <b; i++) lb = lca(blue[i], lb);

		bool poss = true;
		if(lr==lb) poss = false;
		if(anc(lr, lb))for(int i=0;i <r; i++){
			if(!poss) break;
			if(anc(lb, red[i])) poss = false;
		}
		if(anc(lb, lr))for(int i=0;i <b; i++){
			if(!poss) break;
			if(anc(lr, blue[i])) poss = false;
		}	
		if(poss) cout << "YES" << endl;
		else cout << "NO" << endl;
	}



	exit(0);
}
