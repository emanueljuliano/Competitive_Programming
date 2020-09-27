#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;
const int MAX = 1e5+10;

int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		cout << "Case " << cs << ": ";
		ll n; cin >> n;
		string s; cin >> s;
		vector<ll> soma;
		soma.pb(0);
		for(int i=0; i<n; i++){
			soma.pb(soma[i]+s[i]);
		}
		/*
			111111111
			122222221
			123333321
			122222221
			111111111
		*/
		ll ans  =0;
		ll at = 0;
		for(ll i=0; i<n; i++){
			ll inc = soma[n-i] - soma[i];
			at += inc;
		//	cout << " inc= " << inc << " at= " << at << " ans= " << ans << endl;
			ans += at*(i+1)%MOD;
			ans%=MOD;
		}	
		cout << ans << endl;
	}

	exit(0);
}
