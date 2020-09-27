#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int LOG = 31;

int basis[LOG];
int rk;

void insert(int mask){
	for(int i=LOG-1; i>=0; i--) if(mask>>i&1){
		if(!basis[i]){
			basis[i] = mask, rk++;
			return;
		}
		mask ^= basis[i];
	}
}

int query(int k){
	int ret = 0;
	int at = rk-1;
	for(int i=LOG-1; i+1; i--) if(basis[i]){
		if(!(ret&(1<<i)) != !(k&(1<<at))) ret^=basis[i];
		at--;
	}
	return ret;
}

int main(){ _
	int q; cin >> q;
	
	while(q--){
		int t, k; cin >> t >> k;

		if(t==1) insert(k);
		else cout << query(k-1) << endl;
	}
	exit(0);
}
