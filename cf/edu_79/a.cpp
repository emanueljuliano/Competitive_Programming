#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
			
	int n;	
	cin >> n;
	for(int i=0; i<n; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		ll ma = max(a, max(b, c));
		if (2*ma>a+b+c+1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	exit(0);
}
