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


int main(){ _
	int l, c; cin >> l >> c;
	vector M(l, vector(c, char()));
	vector id(l, vector(c, int()));
	vector vis(l, vector(c, bool()));

	for(auto &a : M) for(auto &b : a) cin >> b;
	int n; cin >> n;
	vector<string> v(n);
	for(auto &s : v) cin >> s, sort(s.begin(), s.end());
	
	for(int i=0; i<l; i++) for(int j=0;j <c; j++){
		// direita
		string aux;
		for(int k=i; k<l; k++){ 
			aux+=M[k][j]; 
			sort(aux.begin(), aux.end());
			for(int o=0;o<v.size(); o++) if(aux==v[o]) for(int p=i; p<=k; p++){
				if(id[p][j] and id[p][j] != o+1) vis[p][j] = 1;
				id[p][j] = o+1;
			}
		}
		// baixo
		aux.clear();
		for(int k=j; k<c; k++){ 
			aux+=M[i][k]; 
			sort(aux.begin(), aux.end());
			for(int o=0;o<v.size(); o++) if(aux==v[o]) for(int p=j; p<=k; p++){
				if(id[i][p] and id[i][p] != o+1) vis[i][p] = 1;
				id[i][p] = o+1;
			}
		}
		// diagonal
		aux.clear();
		for(int k=0; i+k<l and j+k<c; k++){ 
			aux+=M[i+k][j+k]; 
			sort(aux.begin(), aux.end());
			for(int o=0;o<v.size(); o++) if(aux==v[o]) for(int p=0; p<=k; p++){
				if(id[i+p][j+p] and id[i+p][j+p] != o+1) vis[i+p][j+p] = 1;
				id[i+p][j+p] = o+1;
			}
		}
		// antidiagonal
		aux.clear();
		for(int k=0; i-k+1 and j+k<c; k++){ 
			aux+=M[i-k][j+k]; 
			sort(aux.begin(), aux.end());
			for(int o=0;o<v.size(); o++) if(aux==v[o]) for(int p=0; p<=k; p++){
				if(id[i-p][j+p] and id[i-p][j+p] != o+1) vis[i-p][j+p] = 1;
				id[i-p][j+p] = o+1;
			}
		}
	}

	int ans = 0;
	for(auto a : vis) for(auto b : a) ans+=b;
	cout << ans << endl;
	exit(0);
}
