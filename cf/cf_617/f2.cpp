#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second
#define ff first

typedef long long ll;
typedef pair<int, int> pii;


vector<int> v[5001];
int visto[5001];
map<pii, int> cor;
bool ans = true;
int ma[1000001];
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
				int cor_at = cor[aux];

				if(cor_at==0) {
						cor[aux] = g; 
						ma[g]++;
				}
				else if( cor_at<g){
					ma[cor_at]--;
					if(	ma[cor_at]==0) ans = false;
					ma[g]++;
					cor[aux] = g;
				}
				else if(cor_at>g) n_marc++;
			return true;
			}
		}
	}
	return false;
}

int main(){ _
	memset(ma, 0, sizeof(ma));
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
		pair<int, int> aux = {a, b};
		out.pb(aux);

		cor[aux] = 0;
	}

	vector<pair<int, pair<int, int>>> query;
	int m; cin >> m;
	for(int i=0; i<m; i++){
		int a, b, g; cin >> a >> b >> g;
		a--; b--;
		if(a>b) swap(a, b);
		query.pb({g, {a, b}});
	}

	sort(query.begin(), query.end(), greater<>());
	query.erase(unique(query.begin(), query.end()), query.end());
	
	for(int i=0; i<query.size(); i++){
		int a, b, g;
		a = query[i].ss.ff;
		b = query[i].ss.ss;
		g = query[i].ff;
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
		for(pair<int, int> x : out){
			int cor_at = cor[x];
			if(cor_at==0) cout << 100000 << " ";
			else{
				cout << cor_at << " ";
			}
		}
		cout << endl;
	}
	exit(0);
}
