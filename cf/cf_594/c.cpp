#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1e9 + 7;

int pd[100500][2];
ll rec(int at, int cor, ll a){
	if (at==a) return 1;
	if(at==a-1) return 1;
	if(pd[at][cor] != -1) return pd[at][cor];
	return pd[at][cor] = (1 + rec(at+1, !cor, a)%MOD + rec(at+2, !cor, a)%MOD)%MOD;
}


int main(){ _
ll n, m;
	memset(pd, -1, sizeof(pd));
	cin >> n >> m;
	ll resp = rec(0, 0, n)%MOD;
	memset(pd, -1, sizeof(pd));
	resp = (resp + rec(0, 0, m))%MOD;
	cout << resp << endl;



	exit(0);
}
