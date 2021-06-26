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
	int n; cin >> n;
	vector<int> v(n);
	vector<ii> pref; pref.pb({0, 0});
	for(auto &i : v) {
		cin >> i;
		if(i==1) pref.pb({pref.back().f+1, pref.back().s});
		if(i==2) pref.pb({pref.back().f, pref.back().s+1});
	}	

	vector<ii> ans;

	auto val = [&](int l, int r, int x){
		return max(pref[r].f-pref[l].f, pref[r].s-pref[l].s) >= x;
	};
	for(int i=1; i<=n; i++){
		bool show = true;
		int it = 0;
		int m1=0, m2=0;
		int at = 0;
		while(it<n){
			int l = it+1, r = n;
			while(l<r){
				int m = (l+r)/2;
				if(val(it, m, i)) r = m;
				else l = m+1;
			}
			if(!val(it, l, i)){show=false; break;}
			else {
				if(pref[l].f-pref[it].f > pref[l].s-pref[it].s) m1++, at=1;
				else m2++, at=2;
				it = l;
			}
		}
		if(m1==m2) show = false;
		if(m1>m2 and at==2) show = false;
		if(m1<m2 and at==1) show = false;
		if(show) ans.pb({max(m1, m2), i});
	}
	
	cout << ans.size() << endl;
	if(ans.size()) sort(ans.begin(), ans.end());
	for(auto [a, b] : ans) cout << a << " " << b << endl;
	
	
	exit(0);
}
