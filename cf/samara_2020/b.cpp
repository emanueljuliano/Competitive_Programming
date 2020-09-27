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


int main(){ _
	ll n, t; cin >> n >> t;
	vector<ll> v;
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	int ans = 0;
	
	int ans1 = 0;
	for(int i=0;i <n; i++){
		if(v[i]>=0 and v[i]<=t) ans1++;
		if(v[i]>t) break;
	}
	ans = ans1;
	ans1 = 0;
	for(int i=n-1;i >=0; i--){
		if(v[i]<=0 and v[i]>=-t) ans1++;
		if(v[i]<-t) break;
	}
	ans = max(ans, ans1);


	for(int i=0;i <n; i++){
		ll at = t-abs(v[i]);
		if(at<0) continue;
		int up = upper_bound(v.begin(), v.end(), max((int)at+(int)v[i], 0)) - v.begin();
		ans = max(ans, up-i);
		if(v[i]<0) {
			up = upper_bound(v.begin(), v.end(), at/2) - v.begin();
			ans = max(ans, up-i);
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
