#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9+7;
const int MAX = 5e6+10;

ll p3[MAX];
ll neg[int(2e3+10)][int(2e3+10)];

int main(){ _
	
	p3[0] = 1;
	for (int i=1; i<MAX; i++) p3[i] = p3[i-1]*3%MOD;

	// neg(8, 2) = 0; neg(6, 4) = 0;
	neg[2][2] = 66;
	neg[3][2] = 390;
	neg[4][2] = 1800;
	neg[5][2] = 6120;
	neg[6][2] = 13680;
	neg[7][2] = 15120;
	neg[3][3] = 3198;
	neg[4][3] = 13176;
	neg[5][3] = 27000;
	neg[6][3] = 13680;
	neg[7][3] = 15120;
	neg[4][4] = 24336;
	neg[5][4] = 4320;
	neg[5][5] = 4320;
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (n < m) swap(n, m);
		
		if (m == 1) cout << 0 << endl;
		else cout << (p3[n*m] - neg[n][m] + MOD)%MOD << endl;
	}
	exit(0);
}
