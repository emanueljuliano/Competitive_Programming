#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n, m; cin >> n >> m;	
	ll sat = 0, sat2=0;
	vector<ll> v;
	v.pb(0);
	vector<ll> soma, soma2;
	for(int i=0;i <n; i++){
		ll a; cin >> a; v.pb(a);
	}
	v.pb(m);

	soma.pb(0); soma2.pb(0);
	for(int i=1;i <v.size(); i+=2){
		sat += v[i]-v[i-1];
		soma.pb(sat);
	}
	
	for(int i=2;i <v.size(); i+=2){
		sat2 += v[i]-v[i-1];
		soma2.pb(sat2);
	}

	ll ans = sat;
//	cout << "vetores" << endl;
//	for(auto k : soma) cout << k<< " ";
//	cout << endl;
//	for(auto k : soma2) cout << k<< " ";
//	cout << endl;

//	cout <<" LOOP" << endl;
	for(int i=0;i <=n; i++){

		ll at = 0;
		if(v[i+1]-v[i]==1) continue;
		at += soma[(i+1)/2];
		at += soma2.back()-soma2[(i+1)/2];
		at += v[i+1]-v[i]-1;

		ans = max(ans, at);
//		cout << i << " " << soma[(i+1)/2] << " " << soma2[(i+1)/2] << endl;
	}
	cout << ans << endl;

	
	exit(0);
}
