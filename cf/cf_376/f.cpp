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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 200005;
int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());
	vector<ll> pref;
	pref.pb(0);
	for(auto u : v) pref.pb(u+pref.back()); 
	ll ans = 0;
	
	vector<ll> suf;
	suf.pb(v.back());
	for(int i=n-2; i>=0; i--) suf.pb(suf.back() + v[i]);
	reverse(suf.begin(), suf.end());
	vector<int> crivo(MAX), mul(n);
	for(int i=0;i <n; i++){
		if(crivo[v[i]]) mul[i] = 1;
		else for(int j=v[i]; j<MAX; j+=v[i]) crivo[j]=1;
	}

	for(int i=0;i <n; i++){
		if(mul[i]) continue;
		if(suf[i] <= ans) break;
		ll at = 0;
		int ant = i;
		for(int j=1; j*v[i]<=v.back(); j++){
			int lo = lower_bound(v.begin(), v.end(), (j+1)*v[i]) - v.begin();
			at += ll(lo-ant)*j*v[i];
			ant = lo;
		}
		ans = max(ans, at);
	}
	cout << ans << endl;
	
	
	
	
	exit(0);
}
