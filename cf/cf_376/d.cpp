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

bool pref(vector<int> a, vector<int> b){
	if(a.size()>=b.size()) return false;
	for(int i=0;i <a.size(); i++) if(a[i]!=b[i]) return false;
	return true;
}

int main(){ _
	int n, c; cin >> n >> c;
	vector<vector<int>> v(n);
	int maxi = 0;
	for(int i=0;i <n; i++){
		int k; cin >> k;
		maxi = max(maxi, k);
		for(int j=0; j<k; j++){
			int a; cin >> a; a--;
			v[i].pb(a);
		}
	}
	
	bool show = true;
	for(int i=0;i <n-1; i++){
		if(pref(v[i+1], v[i])) show = false;
	}
	
	vector<vector<pair<ii, ii>>> range(n);
	for(int i=0;i <n-1; i++){
		for(int j=0; j<min(v[i].size(), v[i+1].size()); j++){
			if(v[i][j]==v[i+1][j]) range[i].pb({{0, c-1}, {0, c-1}});
			else{
				if(v[i][j]<v[i+1][j]) range[i].pb({{0, c-1-v[i+1][j]}, {c-v[i][j], c-1}});
				else range[i].pb({{c-v[i][j], c-1}, {}});
			}
		}
	}
	ii rat = {0, c-1};
	set<int> eq;
	for(int i=0;i <n-1; i++) eq.insert(i);
	int it = 0;
	vector<int> to_erase;
	ii nulo = {0, c-1};
	while(show and eq.size()){
		for(auto u : eq){
			if(rat.s < range[u][it].f or range[u][it].s < rat.f) show = false;
			else{
				rat.f = max(rat.f, range[u][it].f);
				rat.s = min(rat.s, range[u][it].s);
			}
			if(v[u][it] != v[u+1][it] or it>=int(range[u].size())-1) to_erase.pb(u);
		}
		for(auto x : to_erase) eq.erase(x);
		to_erase.clear();
		it++;
	}
	if(show and rat.f<=rat.s) cout << rat.f << endl;
	else cout << -1 << endl;

	exit(0);
}
