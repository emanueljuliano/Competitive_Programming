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

const ll MOD = (1ll<<61)-1;

ll mulmod(ll a, ll b) {
	const static ll LOWER = (1ll<<30)-1, GET31 = (1ll<<31)-1;
	ll l1 = a&LOWER, h1 = a>>30, l2 = b&LOWER, h2 = b>>30;
	ll m = l1*h2 + l2*h1, h = h1*h2;
	ll ans = l1*l2 + (h>>1) + ((h&1)<<60) + (m>>31) + ((m&GET31)<<30) + 1;
	ans = (ans&MOD) + (ans>>61);
	ans = (ans&MOD) + (ans>>61);
	return ans-1;
}

const int MAX = 5e6;

int main(){ _
	vector<ll> v;	
	ll a1 = 1, a2 = 2;
	v = {a1, a2};
	for(int j=0; j<MAX; j++){
		ll aux = a2;
		a2 = (a1+a2)%MOD, a1 = aux;
		v.pb(a2);
	}
	string s; cin >> s;
	ll res = 0;
	for(auto c : s) res = (mulmod(10, res) + c-'0')%MOD;
	for(auto u : v) if(res==u) return cout << "SIM" << endl, 0;

	cout << "NAO" << endl;

	exit(0);
}
