#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

const int LOG = 31;
const int MOD = 1e9+7;

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
	int t; cin >> t; while(t--){
		int n, q; cin >> n >> q;
		
		for(int i=0;i <LOG; i++) basis[i] = 0;
		rk = 0;
	
		for(int i=0;i <q; i++){int a; cin >> a; insert(a);}
		cout << (1<<(n-rk)) << endl;

	}

	exit(0);
}
