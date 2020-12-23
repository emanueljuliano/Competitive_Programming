#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &i : v) cin >> i.f >> i.s;

	sort(v.begin(), v.end());

	set<ii> ans;
	function<void(vector<ii>)> solve = [&](vector<ii> w){
		if(!w.size()) return;
		if(w.size()==1) {ans.insert({w[0]}); return;}
		vector<ii> v1, v2;
		for(int i=0;i <w.size()/2; i++) v1.pb(w[i]);
		for(int i=w.size()/2;i <w.size(); i++) v2.pb(w[i]);	
		assert(v1.size() < w.size());
		solve(v1);
		solve(v2);
		for(auto [x, y] : v1) ans.insert({v1.back().f, y});
		for(auto [x, y] : v2) ans.insert({v1.back().f, y});
	};
	solve(v);
	cout << ans.size() << endl;
	for(auto [a, b] : ans) cout << a << " " << b << endl;


	exit(0);
}
