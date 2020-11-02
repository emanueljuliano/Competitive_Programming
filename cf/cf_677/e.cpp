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


int main(){ _
		
	ll n; cin >> n;
	ll fn = 1;
	for(ll i=1; i<=n; i++) fn*=i;

	ll fn2 = 1;
	for(ll i=1; i<=n/2; i++) fn2*=i;
	cout << fn/fn2/fn2/2LL*(fn2/(n/2)*fn2/(n/2)) << endl;
	
	
	exit(0);
}
