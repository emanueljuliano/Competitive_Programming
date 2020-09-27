#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	vector<ii> q;
	for(int i=0;i <n; i++){
		ll a, b; cin >> a >> b;
		q.pb({a, b});
	}
	sort(q.begin(), q.end());
	ll soma = 0;
	for(int i=0;i <n; i++){
		if(q[i].f < soma) soma += q[i].s;
		else soma = q[i].f + q[i].s;
	}
	cout << soma << endl;
	
	
	
	exit(0);
}
