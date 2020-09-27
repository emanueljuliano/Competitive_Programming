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
	int n, k; cin >> n >> k;
	vector<ll> v;
	for(int i=0;i <n; i++){
		ll a; cin >> a; v.pb(a);
	}
	vector<ll> soma;
	soma.pb(v[n-1]);
	for(int i=n-2; i>=0; i--){
		soma.pb(v[i]+soma.back());
	}
	ll ans = 0;
	ans += soma.back();
	soma.pop_back();
	sort(soma.begin(), soma.end(), greater<>());
	for(int i=0;i <k-1; i++) ans += soma[i];
	cout << ans << endl;
	
	
	
	exit(0);
}
