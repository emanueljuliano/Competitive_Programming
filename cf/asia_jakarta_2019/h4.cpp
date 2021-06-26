#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ld eps = 1e-4;
int main(){ _
	int n; cin >> n;
	ld ans = 0;
	vector<ii> v(n);
	for(auto &i : v) cin >> i.f >> i.s, ans=max(ans, (ld)i.f/2.0*i.s);
	
	vector<pair<ii, int>> ev;
	for(int i=0;i <n; i++) ev.pb({v[i], i}), ev.pb({{v[i].s, v[i].f}, i});
	sort(ev.begin(), ev.end(), greater<>());
	set<ii> st;
	for(auto T : ev){
		int x = T.f.f, y = T.f.s, id = T.s;
		//cout << x << " " << y << " " << id << endl;
		if(!st.size()) {st.insert({y, id}); continue;}

		auto it = st.rbegin();
		auto p = *it;
		auto beg = *st.begin();
		if(p.s==id){	
			if(p!=beg){
				it--;
				ans = max(ans, (ld)x*min(y, it->f));
			}
		}
		else{
			ans = max(ans, (ld)x*min(y, p.f));
		}
		st.insert({y, id});
	}
	ans += eps;
	cout << setprecision(1) << fixed;
	cout << ans << endl;
	
	exit(0);
}
