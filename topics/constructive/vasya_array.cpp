#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;


int main(){ _
	int n, m; cin >> n >> m;
	vector<ii> v, w;
	for(int i=0;i <m; i++){
		int t, l, r; cin >> t >> l >> r; l--, r--;
		if(t) v.pb({l, r});
		else w.pb({l, r});
	}

	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), [](ii a, ii b){
		if(a.s!=b.s) return a.s>b.s;
		return a.f>b.s;
	});

	if(v.size()){
		vector<ii> aux;
		int l2 = v[0].f, r2 = v[0].s;
		for(auto [l, r] : v){
			if(l <= r2) r2 = max(r2, r);
			else{
				aux.pb({l2, r2});
				l2 = l, r2 = r;
			}
		}
		aux.pb({l2, r2});
		v = aux;
	}
	for(auto [l, r] : w){
		for(auto [ll, rr] : v) if(ll<=l and rr>=r) return cout << "NO" << endl, 0;
	}

	vector<int> ans(n), vis(n);
	for(auto [l, r] : v) for(int i=l; i<=r; i++) ans[i] = n-l, vis[i]=1;
	for(int i=0;i <n; i++) if(!vis[i]) ans[i] = n-i;
	
	cout << "YES" << endl;
	for(auto u : ans) cout << u << " ";
	cout << endl;


	exit(0);
}
