#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;

	ll pref = 0, ans = 0;
	priority_queue<ll> pq;
	pq.push(0);
	for (int i=0; i<n; i++) {
		int a; cin >> a; 
		pref -= a;
		
		pq.push(pref), pq.push(pref);
		ll opt = pq.top(); pq.pop();

		ans += opt - pref;
	}

	cout << ans << endl;
	
	
	exit(0);
}
