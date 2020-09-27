#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int vis[50020];

struct p{
	int x, y, z, id;
};

map<int, vector<p>> mx, my, mz;
vector<ii> ans;
bool ord(p a, p b){
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	if(a.z != b.z) return a.z<b.z;
	return a.id < b.id;
}

void solve(vector<p> v){
	if(v.size()<=1) return;
	
	for(int i =0;i <v.size()-1; i+=2){
		p a = v[i];
		p b = v[i+1];
		ans.pb({a.id, b.id});
		vis[a.id]=1;
		vis[b.id]=1;
	}
}

void solvez(int z){
	solve(mz[z]);
}

void solvey(int y){
	mz.clear();
	for(auto a : my[y]) if(!vis[a.id]) mz[a.z].pb(a);
	for(auto k : mz){
		if(k.s.size()>1)
			solvez(k.f);
	}

	vector<p> v;
	for(auto k : mz){
		for(auto a : k.s)
			if(!vis[a.id]) v.pb(a);
	}
	solve(v);
}

void solvex(int x){
	my.clear();
	for(auto a : mx[x]) if(!vis[a.id]) my[a.y].pb(a);
	for(auto k : my){
		if(k.s.size()>1)
			solvey(k.f);
	}
	vector<p> v;
	for(auto k : my){
		for(auto a : k.s)
			if(!vis[a.id]) v.pb(a);
	}
	solve(v);
}

int main(){ _
	memset(vis, 0, sizeof(vis));
	int n; cin >> n;
	vector<p> v;
	for(int i=0;i <n; i++){
		p a; cin >> a.x >> a.y >> a.z;
		a.id = i;
		v.pb(a);
	}
	sort(v.begin(), v.end(), ord);
	for(auto a : v) mx[a.x].pb(a);
	for(auto k : mx){
		if(k.s.size()>1){
			solvex(k.f);
		}
	}
	
	my.clear();
	for(auto a : v) if(!vis[a.id]) my[a.y].pb(a);
	for(auto k : my){
		if(k.s.size()>1){
			solvey(k.f);
		}
	}

	mz.clear();
	for(auto a : v) if(!vis[a.id]) mz[a.z].pb(a);
	for(auto k : mz){
		if(k.s.size()>1){
			solvez(k.f);
		}
	}

	vector<p> w;
	for(auto k : v) if(!vis[k.id]) w.pb(k);
	solve(w);
	
	for(auto k : ans) cout << k.f+1 << " "<< k.s+1 << endl;

	exit(0);
}
