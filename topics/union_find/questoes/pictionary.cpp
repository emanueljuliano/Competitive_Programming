#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define pb push_back

typedef pair <int, int> pii;

const int MAX = 1e5+10;

int id[MAX], ans[MAX];
vector <int> v[MAX];
vector <pii> qu[MAX];
int m;

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	int i = p;
	p = find(p);
 	q = find(q);
	if (p == q) return;
	if(v[p].size() > v[q].size()) swap(p, q);
	
	for (auto k : qu[p]){
		if(find(k.ff) == q) ans[k.ss] = m-i+1;
		else qu[q].pb(k);
	}
	qu[p].clear();

	for(int k : v[p]){
		id[k] = q;
		v[q].pb(k);
	}	
	v[p].clear();
	return;
}

int main(){ _
	int n, q;
	cin >> n >> m >> q;
	for(int i=0; i<=n; i++) id[i] = i, v[i]={i};

	for(int i=0; i<q; i++){
		int a, b;
		cin >> a >> b;
		qu[a].pb({b, i});
		qu[b].pb({a, i});
	}

	for(int i=m; i>0; i--)
		 for(int j=2*i; j<=n; j+=i)
			uni(i, j);	
	
	for(int i=0; i<q; i++)
		cout << ans[i] << endl;
	
	exit(0);
}
