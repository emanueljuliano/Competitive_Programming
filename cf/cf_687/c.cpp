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

int main(){ _
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end(), greater<>());
	vector<ll> pref;
	pref.pb(v[0]);
	for(int i=1;i <n; i++) pref.pb(v[i]+pref.back());

	vector<vector<ll>> part(k+1);
	int it = 0;
	while(it<n and pref[n-1-it]<0) part[it%(k+1)].pb(v[n-1-it]), it++;
	while(it<n) part[0].pb(v[n-1-it]), it++;

	ll ans = 0;
	for(auto u : part) for(int i=0;i <u.size(); i++) ans += u[i]*i;

	cout << ans << endl;


	exit(0);
}
