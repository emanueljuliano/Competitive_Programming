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
	int n, m; cin >> n >> m;
	vector<ll> v(n);
	for(auto &i : v) cin >> i;
	vector<ll> w, v2;
	vector<int> us(n);
	for(int i=0;i <m; i++){
		int a; cin >> a; a--;
		w.pb(v[a]), us[a]=1;
	}
	ll ans = 0;
	for(int i=0;i <n; i++) if(!us[i]) ans+=v[i];
	
	sort(w.begin(), w.end(), greater<>());

	for(auto u : w){
		if(u>ans) ans += u;
		else ans += ans;
	}

	cout << ans << endl;
	
	
	exit(0);
}
