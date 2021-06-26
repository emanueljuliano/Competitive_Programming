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

int main(int argc, char**argv){ _
	srand(stoi(argv[1]));
	
	int mx = 3;
	int t = uniform(1, 1);

	string query = "!?LRDU";
	cout << t << endl;
	while(t--){
		int n = uniform(1, mx), m = uniform(1, mx);
		cout << n << " " << m << endl;
		vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		shuffle(v.begin(), v.end(), rng);
		for (int i=0; i<n; i++) {
			cout << i+1 << " " << v[i]+1 << endl;
		}
		while (m--){
			int q = uniform(0, 5);
			cout << query[q] << " ";
			int a = uniform(1, n);
			if(q) cout << a;
			cout << endl;
		}
	}
	
	exit(0);
}
