#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int x, y, a, b; cin >> x >> y >> a >> b;
		int dif = abs(x-y);
		int mod = a+b;
		if(!(dif%mod)){
			cout << dif/mod << endl;
		}	
		else cout << -1 << endl;
	}


	exit(0);
}
