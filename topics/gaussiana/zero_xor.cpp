#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int LOG = 31;
int basis[LOG]; // basis[i] = mask do cara com bit mais significativo i
int rk; // tamanho da base

void insert(int mask) {
	for (int i = LOG - 1; i >= 0; i--) if (mask>>i&1) {
		if (!basis[i]) {
			basis[i] = mask, rk++;
			return;
		}
		mask ^= basis[i];
	}
}
int main(){ _
	int n; cin >> n;
	int at = 0;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		insert(a);
		at^=a;
	}
	if(!at) cout << -1 << endl;
	else cout << rk << endl;


	exit(0);
}
