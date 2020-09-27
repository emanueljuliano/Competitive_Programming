#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	while(true){
		cin >> n;
		if(n==0) break;
		ll ans = 0;
		for(int i=0; i<n; i++){
			ans += (n-i)*(n-i);
		}
		cout << ans << endl;
	}


	exit(0);
}
