#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef tuple<int, int, int> T;

int main(){ _
	int n, m; cin >> n >> m;
	vector<T> eg;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		eg.push_back({c, a, b});
	}
	for(int i=0;i <n-1; i++) eg.push_back({0, i, i+1});
	
	sort(eg.begin(), eg.end(), greater<>());
	
	vector<int> sz(n, 1), id(n);
	iota(id.begin(), id.end(), 0);
	function<int(int)> find = [&](int p){return (p == id[p]) ? p : find(id[p]);};

	ll ans = 0;
	vector<T> v;
	for(auto e : eg){
		if(!v.size() or get<0>(v.back()) == get<0>(e)) v.push_back(e);
		else{
			for(auto [c, a, b] : v){
				a = find(a), b = find(b);
				if(sz[a]>sz[b]) swap(a, b);
				if(a!=b) ans += sz[a]*(ll)sz[b]*c, id[a]=b, sz[b]+=sz[a];
			}
			v.clear(); v.push_back(e);
		}
		if(get<0>(e) and find(get<1>(e)) == find(get<2>(e))) return cout << -1 << endl, 0;
	}
	for(auto [c, a, b] : v){
		a = find(a), b = find(b);
		if(sz[a]>sz[b]) swap(a, b);
		if(a!=b) ans += sz[a]*(ll)sz[b], id[a]=b, sz[b]+=sz[a];
	}

	cout << ans << endl;
	

	exit(0);
}
