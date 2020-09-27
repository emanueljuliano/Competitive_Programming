#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int LOG = 62;

ll basis[LOG];
int rk;

void insert(ll mask){
	for(int i=LOG-1; i>=0; i--) if(mask>>i&1LL){
		if(!basis[i]){
			basis[i] = mask, rk++;
			return;
		}
		mask ^= basis[i];
	}
}

int main(){ _
	int n; cin >> n;
	for(int i=0;i <n; i++){ll a; cin >> a; insert(a);}
	
	ll ans = 0;
	for(int i=LOG-1; i+1; i--){
		ans = max(ans, ans^basis[i]);
	}

	cout << ans << endl;

	exit(0);
}
