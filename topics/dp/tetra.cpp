#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MOD = 1e9+7;

int pd[(int)1e7+10][2];

int main(){ _
	memset(pd, -1, sizeof(pd));
	int n; cin >> n;
	pd[0][1] = 1;
	pd[0][0] = 0;
	pd[1][1] = 0;
	pd[1][0] = 1;

	for(int i=2; i<=n; i++){
		pd[i][0] = (2*pd[i-1][0]%MOD + pd[i-1][1])%MOD;
		pd[i][1] = (pd[i-1][0] + (pd[i-1][0] + pd[i-1][0])%MOD)%MOD;
	}

	cout << pd[n][1] << endl;

	exit(0);
}
