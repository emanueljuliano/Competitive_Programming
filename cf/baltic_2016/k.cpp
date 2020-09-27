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

set<ll> st;
vector<ll> fat;
const ll MAX = 1e18;

void solve(ll x){
	if(st.count(x) or x>MAX) return;
	st.insert(x);
	for(int i=0;i <fat.size(); i++){
		if(fat[i] > (x+MAX-1)/x) return;
		solve(x*fat[i]);
	}
	return;
}

int main(){ _
	int t; cin >> t;
	fat.pb(1);
	for(ll i=1;i <20; i++) fat.pb(fat[i-1]*i);
	solve(1);
	while(t--){
		ll x; cin >> x;
		if(st.count(x)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
