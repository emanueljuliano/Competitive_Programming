#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;

struct Sor {
	int seg[2 * MAX];
	int n = 0;
	
	Sor() {n = 0;}

	void build(int n2, int *v, int b) {
		n = n2;
		for (int i=n; i<2*n; i++) {
			if (__builtin_popcount(v[i-n]) == b) seg[i] = v[i-n];
			else seg[i] = 0;
		}
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] | seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret |= seg[a];
			if (b % 2 == 0) ret |= seg[b];
		}
		return ret;
	}
};

struct Sand {
	int seg[2 * MAX];
	int n = 0;
	
	Sand() {n = 0;}

	void build(int n2, int *v, int b) {
		n = n2;
		for (int i=n; i<2*n; i++) {
			if (__builtin_popcount(v[i-n]) == b) seg[i] = v[i-n];
			else seg[i] = ~0;
		}
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] & seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = ~0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret &= seg[a];
			if (b % 2 == 0) ret &= seg[b];
		}
		return ret;
	}
};

int v[MAX];

int main(){ _
	int n, q; cin >> n >> q;

	vector last(n+1, vector<int>(30, -1));
	for (int i = 0; i<n; i++) {
		cin >> v[i];
		if (i) for (int j=0; j<30; j++) last[i][j] = last[i-1][j];
		last[i][__builtin_popcount(v[i])] = i;
	}
	
	vector<Sand> sand(30); 
	vector<Sor> sor(30); 
	for (int i=0; i<30; i++) {
		sand[i].build(n, v, i);
		sor[i].build(n, v, i);
	}

	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		
		vector<int> prefor;
		prefor.push_back(sor[0].query(l, r));
		for (int i=1; i<30; i++) {
			prefor.push_back(prefor[i-1] | sor[i].query(l, r));
		}
		vector<int> sufand;
		sufand.push_back(sor[29].query(l, r));
		for (int i=28; i+1; i--) {
			sufand.push_back(sufand.back() & sand[i].query(l, r));
		}
		reverse(sufand.begin(), sufand.end());
	
		bool ans = false;
		for (int i=0; i<30; i++) {
			if (last[r][i] < l and sufand[i] == prefor[i]) ans = true;
			if (i and sufand[i] == prefor[i-1]) ans = true;
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	exit(0);
}
