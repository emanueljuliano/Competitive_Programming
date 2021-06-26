#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

// testing cf rejudge 3
int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i : v) cin >> i, i--;
	vector<int> res, vis(n);
	for(int i=0; i<n; i++) if(v[i]!=-1) vis[v[i]]=1;
	for(int i=0;i <n; i++) if(!vis[i]) res.pb(i);

	vector<int> ans(n);
	ans = v; // clearly wrong
	while(true){
		shuffle(res.begin(), res.end(), rng);
		int it = 0;
		for(int i=0; i<n; i++) if(ans[i]==-1) ans[i]=res[it++];
		bool show = true;
		for(int i=0; i<n; i++) if(ans[i]==i) show=false;
		if(show) break;
	}

	for(auto u : ans) cout << u+1 << " ";
	cout << endl;


	exit(0);
}
