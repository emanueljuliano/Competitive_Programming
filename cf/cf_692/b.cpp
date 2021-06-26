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

int main(){ _
	string s; cin >> s;
	ll x, y; cin >> x >> y;
	
	if(y>x){ // s -> 111100000
		swap(x, y);
		for(auto &c : s) if(c!='?') c = (c=='0') ? '1' : '0';
	}
	
	vector<int> pos;
	for(int i=0;i <s.size(); i++) if(s[i]=='?') pos.pb(i), s[i]='0';

	vector<ll> p0, p1; p0.pb(0), p1.pb(0);
	for(auto u : s){
		p0.pb(p0.back() + (u=='0'));
		p1.pb(p1.back() + (u=='1'));
	}
	
	int n = s.size();
	ll ans = 0;
	for(int i=0;i <n; i++){
		if(s[i]=='0') ans += p1[i]*y;
		if(s[i]=='1') ans += p0[i]*x;
	}
	
	ll a1 = 0, at = ans;
	for(auto p : pos){
		s[p] = '1';
		at -= (p1[n]-p1[p+1])*x + (p1[p]+a1)*y;
		//cout << p << " " << at << " " << s[p] << endl;
		at += (p0[n]-p0[p+1])*y + (p0[p]-a1)*x;
		ans = min(ans, at); a1++;
	}

	cout << ans << endl;

	exit(0);
}
