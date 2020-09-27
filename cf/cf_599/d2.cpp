#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
typedef long long ll;
 
int main(){ _ 
 
	int n, m;
	cin >> n >> m;
	vector <int>  g[100100];
	set <int>  s[100100];
	int a, b;
	set<int> nao_visto;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		s[a].insert(b);
		s[b].insert(a);
	}
	for(int i=1; i<=n; i++)
		nao_visto.insert(i);
	int minv = 0, mina=100100;
	for(int i=1; i<=n; i++){
		if(g[i].size() < mina){
			mina = g[i].size();
			minv = i;
		}
	}	
	set <int> vistos;
	int visto[100100];
	memset(visto, -1, sizeof(visto));
	for(auto i : nao_visto){
		if(!s[minv].count(i)){
			visto[i]=1;
			vistos.insert(i);
			nao_visto.erase(i);
		}
	}
	
	int ans = 0;
	for(int i=0; i<mina; i++){
		int vizinho = g[minv][i];
		if(visto[vizinho] > 0 ) continue;
		if(g[vizinho].size() == n-1){
			 ans++;
			nao_visto.erase(vizinho);
			visto[vizinho] = 1;
			vistos.insert(vizinho);
		}
		else{
			int vv;
			bool flag = true;
			for(auto j : vistos){
				if(!s[vizinho].count(j) and visto[j])
					flag = false;
					 break;
			}
			if(flag){
				ans++;
				for(auto aux : nao_visto){
					if(g[aux].size() < n-1 and !s[vizinho].count(aux)){
						visto[aux] = 1;
						vistos.insert(aux);
						nao_visto.erase(aux);
					}
				}
			}
		}
		visto[vizinho] = 1;
		vistos.insert(vizinho);
		nao_visto.erase(vizinho);
	}
		
	cout << ans << endl;
 
	exit(0);
}
