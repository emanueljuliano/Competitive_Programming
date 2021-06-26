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

int main() { _
	int n;
	ll T; cin >> n >> T;
	map<ll, set<pair<ll, int>>> mp_x, mp_y;
	set<pair<pair<ll, ll>, int>> st;
	vector<ll> x(n), y(n), dir(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> x[i] >> y[i] >> c;
		if (c == 'R') dir[i] = 0;
		if (c == 'U') dir[i] = 1;
		if (c == 'L') dir[i] = 2;
		if (c == 'D') dir[i] = 3;

		mp_x[x[i]].insert({y[i], i});
		mp_y[y[i]].insert({x[i], i});
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({0, 0});
	vector<ll> ini(n, -1);
	while (q.size()) {
		auto [t, idx] = q.top();
		q.pop();

		if (t > T) continue;

		if (ini[idx] == -1) {ini[idx] = t;
		mp_y[y[idx]].erase({x[idx], idx});
		mp_x[x[idx]].erase({y[idx], idx});
		}
		else st.insert({{x[idx], y[idx]}, t});
		if (dir[idx] == 0) {
			auto& se = mp_y[y[idx]];
			ll val = x[idx] + (t - ini[idx]);
			if(st.count({{val, y[idx]}, 0})) continue;
			else st.insert({{val, y[idx]}, 0}); 

			auto it = se.lower_bound({val, INF});
			if (it != se.end()) {
				ll delta = abs(it->first - val);
				if (ini[it->second] == -1) q.push({t + delta, it->second});
				q.push({t + delta, idx});
				//se.erase(it);
			}
		}
		if (dir[idx] == 1) {
			auto& se = mp_x[x[idx]];
			ll val = y[idx] + (t - ini[idx]);
			if(st.count({{x[idx], val}, 1})) continue;
			else st.insert({{x[idx], val}, 1}); 

			auto it = se.lower_bound({val, INF});
			if (it != se.end()) {
				ll delta = abs(it->first - val);
				if (ini[it->second] == -1) q.push({t + delta, it->second});
				q.push({t + delta, idx});
				//se.erase(it);
			}
		}
		if (dir[idx] == 2) {
			auto& se = mp_y[y[idx]];
			ll val = x[idx] - (t - ini[idx]);
			
			if(st.count({{val, y[idx]}, 2})) continue;
			else st.insert({{val, y[idx]}, 2}); 


			auto it = se.lower_bound({val, -INF});
			if (it != se.begin()) {
				it--;
				ll delta = abs(it->first - val);
				if (ini[it->second] == -1) q.push({t + delta, it->second});
				q.push({t + delta, idx});
				//se.erase(it);
			}
		}
		if (dir[idx] == 3) {
			auto& se = mp_x[x[idx]];
			ll val = y[idx] - (t - ini[idx]);
			if(st.count({{x[idx], val}, 3})) continue;
			else st.insert({{x[idx], val}, 3}); 



			auto it = se.lower_bound({val, -INF});
			if (it != se.begin()) {
				it--;
				ll delta = abs(it->first - val);
				if (ini[it->second] == -1) q.push({t + delta, it->second});
				q.push({t + delta, idx});
				//se.erase(it);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ini[i] != -1) {
			if (dir[i] == 0) x[i] += T - ini[i];
			if (dir[i] == 1) y[i] += T - ini[i];
			if (dir[i] == 2) x[i] -= T - ini[i];
			if (dir[i] == 3) y[i] -= T - ini[i];
		}

		cout << x[i] << " " << y[i] << endl;
	}

	exit(0);
}


