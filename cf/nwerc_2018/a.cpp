#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &i: v) cin >> i.f >> i.s;

	vector<ll> s;
	s.pb(0);
	for(auto u : v) s.pb(s.back() + u.f);

	vector<ii> item;
	auto av = [&](int i){
		ld den = item[i].s - item[i].f + 1;
		ld num = s[item[i].s+1] - s[item[i].f];
		return num/den;
	};

	for(int i=0;i <n; i++){
		item.pb({i, i});
		int sz = item.size();
		while(sz>=2 and av(sz-1)<av(sz-2)){
			ii novo = {item[sz-2].f, item[sz-1].s};
			item.pop_back(), item.pop_back();
			item.pb(novo);
			sz--;
		}
	}
	vector<pair<ld, ld>> ans(n);
	for(int k=0; k<item.size(); k++){
		for(int i=item[k].f; i<=item[k].s; i++) ans[i].f = av(k);
	}
	
	s.clear();
	s.pb(0);
	for(auto u : v) s.pb(s.back() + u.s);

	item.clear();

	for(int i=0;i <n; i++){
		item.pb({i, i});
		int sz = item.size();
		while(sz>=2 and av(sz-1)<av(sz-2)){
			ii novo = {item[sz-2].f, item[sz-1].s};
			item.pop_back(), item.pop_back();
			item.pb(novo);
			sz--;
		}
	}
	
	for(int k=0; k<item.size(); k++){
		for(int i=item[k].f; i<=item[k].s; i++) ans[i].s = av(k);
	}
	
	ld ret = 0;
	#define sq(x) (x)*(x)
	for(int i=0;i <n; i++){
		ret += sq(ans[i].f - v[i].f) + sq(ans[i].s - v[i].s);
	}
	cout << setprecision(9) << fixed;
	cout << ret << endl;

	exit(0);
}
