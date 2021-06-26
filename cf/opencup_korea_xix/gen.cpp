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
	srand(atoi(argv[1]));

	int mx = 9;
	int n = uniform(1, mx), m = uniform(1, mx);
	set<pair<int, int>> st;
	for(int i=0;i <m; i++){
		int a = uniform(1, n), b = uniform(1, n);
		if(a==b) continue;
		st.insert({a, b});
	}
	m = st.size();

	cout << n << " " << m << endl;
	for(int i=0;i <n; i++) {
		int l = uniform(1, n), r = uniform(1, n);
		if(l>r) swap(l, r);
		cout << l << " " << r << endl;
	}
	for(auto [a, b] : st) cout << a << " " << b << endl;
	
	exit(0);
}
