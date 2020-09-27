#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second
#define ff first

typedef long long ll;

vector<int> v[5001];
int visto[5001];
map<pair<int, int>, int> cor;
bool ans = true;
vector<int> ma(1000001, 0);
int tam = 0;
int n_marc = 0;


bool dfs(int a, int b, int g){
	visto[a] = 1;
	if(a==b) return true;
	for(int i=0; i<v[a].size(); i++){
		if(visto[v[a][i]] == 0){
			bool c = false;
			int y = v[a][i];
			int x = a;	
			visto[y] =1;
			
			c |= dfs(v[a][i], b, g);
			
			if(c){
				tam++;

				if(x>y) swap(x, y);
				pair<int, int> aux = {x, y};
				if(cor[aux]==0) {
						cor[aux] = g; 
						ma[g]++;
				}
				else if( cor[aux]<g){
					ma[cor[aux]]--;
					if(	ma[cor[aux]]==0) ans = false;
					ma[g]++;
					cor[aux] = g;
				}
				else if(cor[aux]>g) n_marc++;
			return true;
			}
		}
	}
	return false;
}

int main(){ _
	int n;
	cin >> n;
	vector<pair<int, int>> out;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >>b;
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
		if(a>b) swap(a, b);
		out.pb({a, b});

		cor[aux] = 0;
	}
	vector<pair<pair<int, int>, int>> query;
	int m; cin >> m;
	for(int i=0; i<m; i++){
		int a, b, g; cin >> a >> b >> g;
		a--; b--;
		query.pb({{a, b}, g});
		
		for(int i=0; i<=n; i++) visto[i] = 0;
		n_marc = 0;
		tam = 0;

		dfs(a, b, g);
		if(ma[g]==0 or tam==n_marc) ans = false;
	}
	for(int i=0; i<m; i++){
		int a, b, g;
		a = query[i].ff.ff;
		b = query[i].ff.ss;
		g = query[i].ss;
		
		for(int i=0; i<=n; i++) visto[i] = 0;
		n_marc = 0;
		tam = 0;

		dfs(a, b, g);
		if(ma[g]==0 or tam==n_marc) ans = false;
	}


	if(!ans){
		cout << -1 << endl;
	}
	else{
		for(auto x : out){
			if(cor[x]==0) cout << 100000 << " ";
			else{
				cout << cor[x] << " ";
			}
		}
		cout << endl;
	}
	exit(0);
}
