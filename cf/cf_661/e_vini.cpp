#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL

typedef long long ll;
typedef pair<int, int> ii;


vector<ii> arestas;
vector<ll> peso;
vector<int> mult;
vector<int> foi;

vector<vector<ii> > adj;



int dfs(int v)
{
	int ret = 0;
	int folha = 1;
	foi[v] = 1;
	//cout << "visitando " << v+1 << endl;
	for (int i=0; i<adj[v].size(); i++)
	{
		int w = adj[v][i].f;
		//cout << "  achei filho " << w+1 << endl;
		if (foi[w])
			continue;
		folha = 0;
		int a = adj[v][i].s;
		mult[a] = dfs(w);
		ret+=mult[a];
	}
	if (folha)
		return 1;

	return ret;
}

int main(){ _
//	char end = '\n';
	int tttt;cin>>tttt;
	while (tttt--)
	{
		int n;
		ll s;
		cin >> n >> s;

		adj.clear();
		adj.resize(n);

		arestas.clear();
		peso.clear();
		mult.clear();

		for (int i=0; i<n-1; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			x--;
			y--;
			adj[x].pb({y,i});
			adj[y].pb({x,i});
			arestas.pb({x,y});
			peso.pb(w);
		}

		mult.resize(n-1);
		foi.resize(n);
		for (int i=0; i<n; i++)
			foi[i] = 0;
		dfs(0);


		priority_queue<pair<ll,int> > fila;

		ll total = 0;
		for (int i=0; i<n-1; i++)
		{
			fila.push(mp((peso[i]-peso[i]/2)*mult[i], i));
			total += peso[i]*mult[i];
		}

		int conta = 0;
		while (total > s)
		{
			//cout << "total="<<total << endl;
			pair<ll, int> pp = fila.top();
			fila.pop();

			int a = pp.s;
			total -= peso[a]*mult[a];
			peso[a]/=2;
			total += peso[a]*mult[a];
			pp.f = (peso[a]-peso[a]/2)*mult[a];

			fila.push(pp);
			conta++;
		}
		cout << conta << endl;


	}

	exit(0);
}











