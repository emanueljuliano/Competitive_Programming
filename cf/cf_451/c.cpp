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
	map<string, set<string>> mp;

	int n; cin >> n;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		int k; cin >> k;
		for(int j=0; j<k; j++){
			string t; cin >> t;
			mp[s].insert(t);
		}
	}


	auto suf = [&](string a, string b){ // a suf of b
		if(a.size()>=b.size()) return false;
		for(int i=1; i<=a.size(); i++) if(a[a.size()-i] != b[b.size()-i]) return false;
		return true;
	};

	map<string, vector<string>> ans;
	for(auto [p, w] : mp){
		set<string> forbiten;
		vector<string> v;
		for(auto u : w) v.pb(u);
		for(auto u : v) for(auto s : w) if(suf(u, s)) forbiten.insert(u);
		for(auto u : w) if(!forbiten.count(u)) ans[p].pb(u);
	}
	
	cout << ans.size() << endl;
	for(auto [p, w] : ans){
		cout << p << " " << w.size() << " ";
		for(auto u : w) cout << u << " ";
		cout << endl;
	}
	
	
	exit(0);
}
