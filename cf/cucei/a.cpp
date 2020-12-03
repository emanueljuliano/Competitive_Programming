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

const int MAX = 1e6;
int d[MAX];
vector<pair<int,int>> g[MAX]; // {vizinho, peso}
int p=0;
void dijkstra(int x) {
	for(int i=0; i <=p; i++) d[i] = INF;
	d[x] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,x});
 
	while(pq.size()) {
		auto [ndist,u] = pq.top(); pq.pop();
		if(-ndist > d[u]) continue;
 
		for(auto [idx,w] : g[u]) if(d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

int main(){ _
	int n, m, x; cin >> n >> m >> x;
	set<ii> st;
	st.insert({x, 0});

	auto add = [&](int l, int r){
		auto it = st.lower_bound({l, -1});
		vector<ii> erase;
		while(it != st.end() and it->f <= r) erase.pb(*it), it++;
		if(erase.empty()) return;
		for(auto u : erase) st.erase(u);
		if(l>1){
			p++;
			for(auto [y, u] : erase) g[u].pb({p, y-l+1});
			st.insert({l-1, p});
		}
		if(r<n){
			p++;
			for(auto [y, u] : erase) g[u].pb({p, r-y+1});
			st.insert({r+1, p});
		}
		return;
	};

	for(int i=0;i <m; i++){
		int f, l, r; cin >> f >> l >> r;
		if(f==1 and l==1 and r==n) return cout << -1 << endl, 0;
		if(f==1) add(l, r);
		else add(1, l-1), add(r+1, n);
	}
	p++;
	for(int i=0;i <p; i++) if(g[i].empty()) g[i].pb({p, 0});
	
	dijkstra(0);
	cout << d[p] << endl;

	exit(0);
}
