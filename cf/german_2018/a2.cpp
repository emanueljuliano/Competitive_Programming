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

const int MAX = 1005*1005;
const int MAX2 = log2(MAX)+1;
vector<vector<int>> g(MAX);
int h, m;
int f(int x, int y){ return x*m+y;}
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];
int D[MAX];
void dfs(int k) {
	in[k] = p++;
	for (auto u : g[k])
		if (in[u] == -1) {
			pai[0][u] = k;
			D[u] = D[k]+1;
			dfs(u);
		}
	out[k] = p++;
}

void build(int raiz=0) {
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
	string str;
	cin >> h >> m;
	getline(cin, str);
	getline(cin, str);
	for(int i=0;i <h; i++){
		getline(cin , str);
		for(int j=1; j<str.size()-1; j+=2){
			int a = f(i, j/2);
			if(i!=n-1 and str[j]==' '){
				int b = f(i+1, j/2);
				g[a].pb(b); g[b].pb(a);
			}
			if(j/2 != m-1 and str[j+1]==' '){
				int b = f(i, j/2+1);
				//		cout << "entrou? " << a << " " << b << endl;
				g[a].pb(b), g[b].pb(a);
			}
		}
	}
	/*	for(int i=0;i <n; i++) for(int j=0; j<m; j++){
		cout << f(i, j) << ": ";
		for(auto x : g[f(i, j)]) cout << x << " ";
		cout << endl;
		}
		*/
	n = h*m;
	D[0] = 0;
	build();

	int q; cin >> q;
	vector<int> v;
	while(q--){
		int a, b; cin >> a >> b; a--; b--;
		v.pb(f(a, b));
	} q = v.size();
	ll ans = 0;
	for(int i=0;i <q-1; i++){
		ans +=  D[v[i]]+D[v[i+1]] - 2*D[lca(v[i], v[i+1])];
	}
	cout << ans << endl;

	exit(0);
}

