#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

const int LOG = 30;
const int MOD = 100000007;

int basis[LOG]; // basis[i] = mask do cara com bit mais significativo i
int rk=0; // tamanho da base

void insert(int mask) {
	for (int i = LOG - 1; i >= 0; i--) if (mask>>i&1) {
		if (!basis[i]) {
			basis[i] = mask, rk++;
			return;
		}
		mask ^= basis[i];
	}
}

int get(int mask) {
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--) if (mask>>i&1) {
		if (!basis[i]) return -1;
		mask ^= basis[i], ret |= (1<<i);
	}
	return ret;
}

int main(){ _
	int t; cin >> t;

	vector<ll> p2(1010);
	p2[0] = 1;
	for(int i=1; i<1010; i++) p2[i] = p2[i-1]*2%MOD;
	int cs = 0;
	while(t--){ cs++;
		memset(basis, 0, sizeof basis);
		rk = 0;
		cout << "Case " << cs << ": ";

		int n, m; cin >> n >> m;
		ll ans = p2[n];
		vector<int> va(n), vb(m);
		for(auto &i: va) {
			cin >> i; insert(i);
		}
		for(auto &i: vb) {cin >> i; 
			if(get(i) != -1){
				ans = (ans - p2[n-rk] + MOD)%MOD;	
			}
		}

		cout << ans << endl;

	}
	exit(0);
}
