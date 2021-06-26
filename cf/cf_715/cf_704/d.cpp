#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int a, b, k; cin >> a >> b >> k;
	if (a+b==k or a+b==k-1) cout << "No" << endl;
	else if (b == 1 and k != 0) cout << "No" << endl;
	else if (b == 1 and k == 0) {
		cout << "Yes" << endl;
		string x(a+b, '0'), y(a+b, '0');
		x[0] = '1', y[0] = '1';
		cout << x << endl;
		cout << y << endl;
	}
	else if (a == 0 and k != 0) cout << "No" << endl;
	else if (a == 0 and k == 0) {
		cout << "Yes" << endl;
		string x(a+b, '1');
		cout << x << endl << x << endl;
	}
	else {
		string x(a+b, '0'), y(a+b, '0');
		x[0] = '1', y[0] = '1';
		for (int i=1; i<=a; i++) x[i] = '0', y[i] = '0';
		for (int i=a+1; i<a+b; i++) x[i] = '1', y[i] = '1';
		
		int cur = 0;
		for (int i=a; i>0; i--) {
			cur++;
			if (cur == k)  {
				x[i] = '1', x[a+1] = '0';
				break;
			}
		}
		if (cur < k) {
			x[1] = '1', x[a+1] = '0';	
		}
		for (int i=a+2; i<a+b; i++) {
			cur++;
			if (cur == k)  {
				x[i] = '0', x[a+1] = '1';
				break;
			}
		}
		if (cur < k) cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			cout << x << endl;
			cout << y << endl;
		}
	}
	
	exit(0);
}
