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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n, c, m; cin >> n >> c >> m;
	vector<pair<int, string>> v;
	vector<string> ans;
	for(int i=0;i <n; i++){
		string a; int x; cin >> a >> x;
		v.pb({x, a});
	}
	sort(v.begin(), v.end(), greater<>());
	ll tot = 0;
	for(int i=0;i <m; i++){
		tot += v[i].f;
		ans.pb(v[i].s);
		if(tot>=c) break;
	}
	if(tot<c) return cout << "impossible" << endl, 0;

	cout << ans.size() << endl;
	for(auto x : ans) cout << x << ", YOU ARE FIRED!" << endl;
	
	
	
	exit(0);
}
