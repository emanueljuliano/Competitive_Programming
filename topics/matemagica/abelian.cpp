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

// pentagon numbers = n(3n - 1)/2
const int MAX = 2e5;
const int MOD = 1e9+7;

int part[MAX];
void partition(int n){
	vector<int> p;
	for(int i=1; i*i<=n; i++)
		p.pb(i*(3*i - 1)/2), p.pb(i*(3*i + 1)/2); 
	part[0] = 1;
	for(int i=1; i<=n; i++) for(int j=0; p[j]<=i; j++){
		if(j%4 < 2) part[i] = (part[i] + part[i-p[j]])%MOD;
		else part[i] = (part[i] - part[i-p[j]] + MOD)%MOD;
	}
}

int main(){ _
	partition(1000);
	
	ll n; cin >> n;
	
	vector<ii> fac;
	for(ll i=2; i*i<=n; i++) if(n%i==0){
		int cnt = 0;
		while(n%i==0)
			n/=i, cnt++;
		fac.pb({n, cnt});
	}
	if(n!=1) fac.pb({n, 1});

	ll ans = 1;
	for(auto [a, b] : fac){
		ans *= part[b];
	}
	cout << ans << endl;

	exit(0);
}
