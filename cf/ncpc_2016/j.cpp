#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n1; cin >> n1;
	int n2; cin >> n2;
	if (n1 == n2) cout << 0 << endl;
	else if (n1 < n2) {
		int a = n2 - n1;
		int b = 360-n2 + n1;
		
		if (abs(a) <= abs(b)) cout << a << endl;
		else cout << -b << endl;
	}
	else {
		int a = 360-n1 + n2;
		int b = n1 - n2;
		
		if (abs(a) <= abs(b)) cout << a << endl;
		else cout << -b << endl;
	}
	
	
	exit(0);
}
