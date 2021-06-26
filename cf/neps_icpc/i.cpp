#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << " " << 1 << " " << 1 << endl;
		cout << "A 0 0 U" << endl;
	}
	else if (n == 2 or n == 3 or n == 5) cout << "impossible" << endl;
	else if (n%2 == 0) {
		int a = 1, b = n/2-1, c = n/2;
		cout << a << " " << b << " " << c << endl;
		for (int i=0; i<c-1; i++) {
			cout << "A " << i << " " << 0 << " U" << endl;
			cout << "A " << i << " " << 1 << " D" << endl;
		}
		cout << "A " << c-1 << " " << 0 << " U" << endl;
		cout << "B 0 1 U" << endl;
	}
	else if (n%2 == 1) {
		int a = 2, c = (n-3), b = (c-a)/2;
		cout << a << " " << b << " " << c << endl;
		for (int i=0; i<c-2; i+=2) {
			cout << "A " << i << " " << 0 << " U" << endl;
			cout << "A " << i << " " << 2 << " D" << endl;
		}
		cout << "A " << c-2 << " " << 0 << " U" << endl;
		cout << "B 0 2 U" << endl;
		cout << "B 0 " << 2+b << " U" << endl;
		cout << "B 0 " << 2+b << " D" << endl;
		cout << "B " << b << " 2 U" << endl;
	}
	
	
	
	exit(0);
}
