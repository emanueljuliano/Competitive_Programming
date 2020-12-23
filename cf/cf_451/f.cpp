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

ll fpow(ll x, ll y) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = mulmod(ret, x);
		y >>= 1;
		x = mulmod(x, x);
	}
	return ret;
}

int main(){ _		
	string s; cin >> s;
	
	vector<ll> p10(s.size()+1), inv10(s.size()+1);
	p10[0] = 1;
	for(int i=1; i<=s.size(); i++) p10[i] = mulmod(p10[i-1], 10);
	inv10[0] = 1;
	ll i10 = fpow(10, MOD-2);
	for(int i=1; i<=s.size(); i++) inv10[i] = mulmod(inv10[i-1], i10);

	vector<ll> pref;
	pref.pb(0);
	reverse(s.begin(), s.end());
	for(int i=0; i<s.size(); i++) pref.pb((pref.back() + mulmod(s[i]-'0', p10[i]))%MOD);

	auto val = [&](int l, int r){
		if(r<l) return -LINF;
		if(r>=s.size() or l<0) return -LINF;
		if(s[r]=='0' and r-l>0) return -LINF;
		return mulmod((pref[r+1] - pref[l] + MOD)%MOD, inv10[l]);
	};

	ll a, b, c;
	int ma=-1, eq=-1;
	for(int i=0;i <s.size(); i++){
		a = pref[i+1];
		for(int j=-3; j<=2; j++){
			int ib = i+1+i+1+j;
			b = val(i+1, ib);
			c = val(ib+1, s.size()-1);
			if((b+c)%MOD==a){
				eq = s.size()-i-1, ma = s.size()-(ib+1);
			}
		}
		for(int j=-3; j<=2; j++){
			int ic = s.size()-1-i-1-j;
			b = val(i+1, ic-1);
			c = val(ic, s.size()-1);
			if((b+c)%MOD==a){
				eq = s.size()-i-1, ma = s.size()-(ic);
			}
		}
	}
	string ans;
	reverse(s.begin(), s.end());
	for(int i=0;i <s.size(); i++){
		if(i==ma) ans+='+';
		if(i==eq) ans += '=';
		ans+=s[i];
	}
	cout << ans << endl;
	
	exit(0);
}
