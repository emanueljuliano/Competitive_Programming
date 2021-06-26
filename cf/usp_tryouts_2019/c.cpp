#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, q; cin >> n >> q;	
	map<int, int> mp;
	set<pair<int, int>> st;

	for (int i=1; i<=n; i++) {
		int a; cin >> a;
		mp[i] = a;
		st.insert({a, i});
	}
	
	while (q--) {
		char c; cin >> c;
		if (c == '?') {
			int a; cin >> a;
			ll soma = st.begin()->first, ans = 1;
			int id = st.begin()->second;
			while (true) {
				auto it = st.lower_bound({soma, id+1});
				if (it == st.end()) break;
				auto at = *it;

				if (id != a and soma <= mp[a] and soma + at.first > mp[a]) 
					soma += mp[a];
				else soma += at.first;
				
				//cout << soma << " ";
				id = -INF;
				ans++;
			}
			cout << ans << endl;
		}
		else if (c == '-') {
			int a; cin >> a;
			st.erase({mp[a], a});
		}
		else if (c == '+') {
			int a, b; cin >> a >> b;
			mp[b] = a;
			st.insert({a, b});
		}
	}
	
	exit(0);
}
