#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, k; cin >> n >> k;
	if (k == 0) {
		cout << -1 << endl;
	}
	else if (n == k) {
		cout << n;
		for (int i=1; i<n; i++)
			cout << " " << i;
		cout << endl;
	}
	else if (k % 2 == 0) {
		int at = 0;
		for (int i=0; i<k/2; i++) {
			cout << 2*i+2 << " " << 2*i+1;
			at = 2*i+2;
			if (i != k/2-1) cout << " ";
		}
		for (int i=at+1; i<=n; i++) {
			cout << " " << i;
		}
		cout << endl;
	}
	else {
		cout << 1;
		int at = 1;
		for (int i=1; i<=k/2; i++) {
			cout << " " << 2*i+1 << " " << 2*i;
			at = 2*i+1;
		}
		for (int i=at+1; i<=n; i++) {
			cout << " " << i;
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
