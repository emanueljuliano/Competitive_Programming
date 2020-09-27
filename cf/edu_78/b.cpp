#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		ll a, b;
		cin >> a >> b;
		ll ans = 0;
		if(a==b){cout << 0 << endl; continue;}
	//	ll dif = abs(a-b);
		ll mini = min(a, b);
		ll maxi = max(a, b);
		for(ll i=1; i<=maxi; i++){
			mini+=i;
			if(mini-maxi>=0 and (mini-maxi)%2==0){
				 cout << i << endl;
				break;
			}
		}
	}


	exit(0);
}
