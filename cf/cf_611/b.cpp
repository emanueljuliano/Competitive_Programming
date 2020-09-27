#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin  >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int aux = m/2;
		int cada = n/m;
		int ans = cada * (m-aux);
		if (n-ans >= aux*(cada+1)){
			ans += (cada+1)*aux;
		}
		else{
			ans  = n;	
		}
		cout << ans << endl;
	}


	exit(0);
}
