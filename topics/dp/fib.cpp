#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

ll f[66];

ll fib(int x){
	if(f[x]!=-1) return f[x];
	return f[x] = fib(x-1) + fib(x-2);
}

int main(){ _
	memset(f, -1, sizeof(f));
	f[0] = 0;
	f[1] = 1;

	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		cout << "Fib(" << x << ") = " << fib(x) << endl;	
	}
	exit(0);
}
