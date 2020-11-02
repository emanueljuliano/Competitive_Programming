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


int main(){ _
	ll n, m, a, d; cin >> n >> m>> a >> d;
	vector<ll> v(m);
	for(auto &i: v) cin >> i;

	sort(v.begin(), v.end());
	
	ll last = 0;
	ll ans = 0;
	if(d<a){
		for (ll i : v) {
			//	cout << i << " " << last << " " << ans << endl;
			if(i <= last) continue;
			if(i<=a) {last = i+d, ans++; continue;} 
			ll ua = min(i/a*a, n*a);
			if(ua > last)  ans += (ua - last-1)/a + 1, last = ua+d;
			if(i <= last) continue;
			ans++;
			last = i+d;
		}
		//	cout  << last << " " << ans << endl;
		if(last < n*a){
			ll l = (last+a)/a*a;
			ans += (n*a-l)/a+1;
		}
	}
	else{
		for (ll i : v) {
		//	cout << i << " " << last << " " << ans << endl;
			if(i <= last) continue;
			if(i<=a) {last = i+d, ans++; continue;} 
			ll ua = min(i/a*a, n*a);
			if(ua > last)  {
				ll pa = (last+a)/a*a;
				
				ll div = (d+a)/a;
			//	cout << "ua " << ua << " " << pa << " " << div << endl;
				ans += (ua-pa)/a/div+1;
				ll aesimo = ((ua-pa)/a+1) % div;
				last = ua-((aesimo-1+div)%div)*a + d;
		//		cout << aesimo << " " << ans << " " << last << endl;
			}
			if(i <= last) continue;
			ans++;
			last = i+d;
		}
		//	cout  << last << " " << ans << endl;
		if(last < n*a){
			ll pa = (last+a)/a*a;
			ll div = (d+a)/a;
			ans += (n*a-pa)/a/div+1;
		}
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
