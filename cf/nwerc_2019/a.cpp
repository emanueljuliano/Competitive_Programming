#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5 + 10;

vector<pair<ll,ll>> perv[MAX];
int last[MAX];

int main(){ //_
#warning fast IO
	int n, w; cin >> n >> w;

	for(int i = 0; i < MAX; i++) perv[i].emplace_back(0, 0);

	vector<int> pts(n, 0), when(n, 0), rank(w + 1, 1);
	vector<ll> srank(n, 0);

	for(int we = 1; we <= w; we++) {
		int k; cin >> k;
		vector<int> wpts(k);
		for(int& i : wpts) {
			cin >> i; i--;

			auto [ltime, psum] = perv[pts[i]].back();
			perv[pts[i]].emplace_back(we, psum + (we - ltime) * rank[pts[i]]);			

			pair<ll,ll> need(when[i], -INF);
			auto it = lower_bound(perv[pts[i]].begin(), perv[pts[i]].end(), need);
			
			ll bsum = (it == perv[pts[i]].begin() ? 0 : it->second);

			srank[i] += perv[pts[i]].back().second - bsum;

			pts[i]++;
			
			auto [altime, apsum] = perv[pts[i]].back();
			perv[pts[i]].emplace_back(we, apsum + (we - altime) * rank[pts[i]]);	

			when[i] = we;
			rank[pts[i]-1]++;
		}

		cout << "perv" << endl;
		for(int i = 0; i <= w; i++) {
			cout << "pt[" << i << "] = ";
			for(auto [time, sum] : perv[i]) cout << "{" << time << ", " << sum << "} ";
			cout << endl;
		}
		cout << endl;

		cout << "srank: ";
		for(auto u : srank) cout << u-1 << ' ';
		cout << endl;

		cout << "when: ";
		for(auto u : when) cout << u << ' ';
		cout << endl << endl;
	}
	for(int i = 0; i < n; i++) {
		auto [ltime, psum] = perv[pts[i]].back();
		perv[pts[i]].emplace_back(w + 1, psum + (w +1 - ltime) * rank[pts[i]]);		

		pair<ll,ll> need(when[i], -INF);
		auto it = lower_bound(perv[pts[i]].begin(), perv[pts[i]].end(), need);

		ll bsum = (it == perv[pts[i]].begin() ? 0 : it->second);

		srank[i] += perv[pts[i]].back().second - bsum;
	}

	cout << "perv" << endl;
	for(int i = 0; i <= w; i++) {
		cout << "pt[" << i << "] = ";
		for(auto [time, sum] : perv[i]) cout << "{" << time << ", " << sum << "} ";
		cout << endl;
	}
	cout << endl;

	cout << "srank: ";
	for(auto u : srank) cout << u-1 << ' ';
	cout << endl;

	cout << "when: ";
	for(auto u : when) cout << u << ' ';
	cout << endl << endl;

	
	cout << fixed << setprecision(10);
	for(auto rnk : srank) cout << (ld) (rnk - 1) / w << endl;

	return 0;
}

