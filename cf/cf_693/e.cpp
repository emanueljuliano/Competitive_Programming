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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> h(n), w(n);
		for(int i=0;i <n; i++){
			int a, b; cin >> a >> b;
			h[i]=a, w[i]=b;
		}
		
		vector<ii> ev, vw;
		for(int i=0;i <n; i++) ev.pb({h[i], i}), vw.pb({w[i], i});
		sort(ev.begin(), ev.end());
		sort(vw.begin(), vw.end());

		int prev = ev[0].f;
		vector<int> add;
		set<ii> sh, sw;
		int itw = 0;
		vector<int> ans(n, -1);
		for(auto [x, id] : ev){
			while(itw<n and vw[itw].f < x) sw.insert({h[vw[itw].s], vw[itw].s}), itw++;
			if(!sw.empty()){
				auto it = *sw.begin();
				if(it.f<w[id]) ans[id] = it.s+1;
			}
			if(x > prev){
				for(auto u : add) sh.insert({w[u], u});
				add.clear();
				prev = x;
			}
			if(!sh.empty()){
				auto it = *sh.begin();
				if(it.f<w[id]) ans[id] = it.s+1;
			}
			add.pb(id);
		/*	cout << x << " vez "<< id+1 << endl;
			cout << "sw" << endl;
			for(auto u : sw) cout << u.f << " "<< u.s+1 << endl;
			cout << "sh" << endl;
			for(auto u : sh) cout << u.f << " "<< u.s+1 << endl;
		*/}

		for(auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
