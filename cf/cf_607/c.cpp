#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const ll MOD = 1e9+7;

int main(){ _
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		ll x;
		cin >> x;	
		string s; cin >> s;
		ll n = s.size();
		ll ans = n;
		for(ll i=1; i<=x; i++){
			for(ll ii=0; ii<(ll)(s[i-1]-'0')-1; ii++)for(ll j=i; j<ans; j++){
				if(s.size()>x+100) break;
				s.pb(s[j]);
			}
			//cout << s << endl;
			ans  = ((ans+MOD)%MOD + ((ll)((ll)(s[i-1]-'0')-1))*(ll)((ans-(ll)i)%MOD) +MOD)%MOD;
			ans%=MOD;
		}
		cout << (ans+MOD)%MOD << endl;
	}


	exit(0);
}
