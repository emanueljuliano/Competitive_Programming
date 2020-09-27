#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;

vector <map <int, int>  > g(100100);
vector  <map <int, int> > gi(100100);
vector <int>  visto(100100, 0);
set <int> cou;
void dfs(int x){
	vector<int> dev;
	vector <int> id;
	int soma = 0;
	for(auto i : gi[x]){
		dev.pb(i.ss);
		id.pb(i.ff);
		soma += i.ss;
		cout << x << " " <<soma << endl;
	}
	int it= 0;
	if(g[x].size()==0) return;
	for(auto i : g[x]){
		int v = i.ff;
		int p = g[x][v];
		cout << "comeca " << x+1 << " viz " << v+1 << " deve " << p << " possui " << soma << endl;
			if(soma>0 and p>0){if(soma>=p){
				soma -= p;	
				for(int j=it; j<dev.size(); j++){
					if(dev[j]>= p) {dev[j]-=p;
					g[id[j]][v] += p;
					gi[v][id[j]] += p;
					 break;}

					else{
					g[id[j]][v] += dev[j];
					gi[v][id[j]] += dev[j];	
					p-=dev[j]; dev[j]=0; it++;}
				}
				gi[v][x] = 0;
			}
			else{
				for(int j=it; j<dev.size(); j++){
					g[id[j]][v] += dev[j];
					gi[v][id[j]] += dev[j];	
					dev[j]=0, it++;
	
				}
				gi[v][x] = p-soma;
				soma = 0;
					
			}
				if(!cou.count(v) and g[v].size()>0 and gi[v].size()>0){
					cou.insert(v);
					dfs(v);
				}
		}
	}
	it = 0;
	for(auto i : gi[x]){
		gi[x][i.ff] = dev[it];
		it++;
	}
}

int main(){ 
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, c;
		map<int, int> mapa, mapa2;
		cin >> a >> b >>c;
		a--; b--;
		if(g[a].count(b)){
			g[a][b] += c;
		}
		else g[a][b]=c;
		if(gi[b].count(a)){
			gi[b][a] += c;
		}
		else gi[b][a] = c;
	}
	for(int i =0; i<n; i++) visto[i] = 0;
	for(int i=0; i<n; i++){
			dfs(i);
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for (auto j : gi[i]){
			if(j.ss>0) ans++;
		}
	}
	cout << ans << endl;
	for(int i=0; i<n; i++){
		for (auto j : gi[i]){
			if(j.ss>0){
				cout << j.ff+1 << " " << i+1 << " " << j.ss << endl;
			}
		}
	}
	
	exit(0);
}
