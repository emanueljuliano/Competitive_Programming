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
	
	int n = uniform(1, 1000);
	int m = uniform(1, 1000);
	cout << n << " " << m << endl;
	for (int i=0; i<n; i++) 
		cout << uniform(0, (1<<30)-1) << " ";
	cout << endl;
	for (int i=0; i<m; i++) {
		int l = uniform(1, n), r = uniform(1, n);
		if (l > r) swap(l, r);
		cout << l << " " << r << endl;
	}
	
	exit(0);
}