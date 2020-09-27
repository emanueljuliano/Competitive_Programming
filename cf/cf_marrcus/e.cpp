#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;

int dist[10100];
int processado[10100];
vector <pii> G[1100];
map <pair<string, string> ,  int> pstr;
int n, m, l;


int lev(string s, string t){
	int d[20][20] = {0};

	for(int i=1; i<= s.size(); i++){
		d[i][0] = i;
	}
	for(int i=1; i<=t.size(); i++){
		d[0][i] = i;
	}
	int cost;
	for(int i=1; i<=s.size(); i++){
		for(int j=1; j<=t.size(); j++){
			if(s[i]==t[i]) cost = 0;
			else cost = 1;
			d[i][j] = min(min(d[i-1][j]+1, d[i][j-1]+1), d[i-1][j-1] + cost);
		}
	}
	return d[s.size()][t.size()];
}

int peso(string a, string b){
	pair<string, string> par = make_pair(a, b);
	if(pstr.count(par)) return pstr[par];
	return pstr[par] = lev(a, b);
}

bool flag = false;
int vizitados[11000];

int resp(int v){
	if (v==n){ flag=true; return 0;}
	int mini = inf;
	for(auto vizinho: G[v]){
		if(vizitados[vizinho]) continue;
		mini = min(peso(v, vizinho) + resp(vizinho));
	}
	return mini;
}


int main(){ _
	memset(vizitados, -1, sizeof(vizitados));
	cin >> n >> m >> l;
	int a, b;
	vector <string> s(1100);
	int v[1100][2];

	for(int i=0; i<m; i++)
		cin >> v[i][0] >> v[i][1];

	string entrada[110];

	for(int i=0; i<l; i++)
		cin >> entrada[i];
	
	int p;

	for(int i=0; i<m; i++){
		a = v[i][0];
		b = v[i][1];
		G[a].pb(b);
	}	
	cout << resp(1) << endl;
	exit(0);
}
