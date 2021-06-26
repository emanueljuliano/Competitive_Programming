#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

const int MAX = 5e5;
ll F[MAX], A[MAX];

int m;
string bs(ll x) {
	string s(m, '0');
	for (ll j = 0; j<m; j++) if (x & (1ll << j)) s[j] = '1';
	return s;
}

int main(){ _
	
	int n, p; cin >> n >> m >> p;

	vector<ll> v(n);
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		for (ll j = 0; j<s.size(); j++) if (s[j] == '1') v[i] += (1ll << j);
	}

	ll ans = 0;
	for (int test = 0; test<15; test++) {
		memset(A, 0, sizeof A);

		int chosen = uniform(0, n-1);
		//cout << "chosen " << chosen << endl;
		vector<ll> w(n);
		for (int i=0; i<n; i++) {
			int at = 0;
			for (int j=0; j<m; j++) {
				if(v[chosen] & (1ll << j)) {
					if (!(v[i] & (1ll << j))) 
						w[i] += (1ll << at);
					at++;
				}
			}
		//	cout << i << " " << bs(w[i]) << endl;
			A[w[i]]++;
		}
		int N = __builtin_popcountll(v[chosen]);
		for(int i = 0; i<(1<<N); ++i) F[i] = A[i];
		for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
			if(mask & (1<<i))
				F[mask] += F[mask^(1<<i)];
		}
		
		for(int i = 0; i<(1<<N); ++i) {
		//	cout << bs(i) << " " << F[i] << endl;
			if (F[i] >= (n+1)/2) {
				int pos = 0;
				for (int j=0; j<N; j++) {
					if (i & (1<<j)) continue;
					else pos += (1<<j);
				}
		//		cout << "pos " << bs(pos) << endl;
				ll pos_ans = 0;
				int at = 0;
				for (int j=0; j<m; j++) {
					if(v[chosen] & (1ll << j)) {
						int has = pos & (1<<at);
		//				cout << j << " " << at << " " << has << endl;
						if (has != 0) pos_ans += (1ll<<j);
						at++;
					}
				}
		//		cout << "pos_ans " << pos_ans << " " << bs(pos_ans) << endl;
				if (__builtin_popcountll(pos_ans) > __builtin_popcountll(ans)) 
					ans = pos_ans;
			}
		}
	}
	cout << bs(ans) << endl;


	exit(0);
}
