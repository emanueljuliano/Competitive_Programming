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

bool good(ll n){
	vector<ll> dig;
	ll aux = n;
	while(aux>0){
		if(aux%10) dig.pb(aux%10);
		aux/=10;
	}

	for(auto u : dig) if(n%u) return false;
	return true;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		while(!good(n)) n++;
		cout << n << endl;
	}
	
	
	
	exit(0);
}
