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
	cout << (-100)%10 << endl;
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v;
		for(int i=0;i <n; i++){
			ll a; cin >> a; v.pb(a);
		}
		set<ll> st;
		for(ll i=0; i <n; i++){
			ll at = i + v[i];
			if(at<0) at -= (at-n+1)/n * n;
		//	cout << at << " ";
			at += 2*n;
			st.insert((at)%n);
		}
		if(st.size() < n) cout << "NO" << endl;
		else cout << "YES" << endl;
	
	}
	
	
	
	exit(0);
}
