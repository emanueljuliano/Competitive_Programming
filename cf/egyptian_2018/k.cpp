#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	#warning FILE IN 
    freopen("string.in", "r", stdin);	

	int t; cin >> t;
	while (t--) {
		string s, p; cin >> s >> p;
		int q; cin >> q;

		vector pref(s.size(), vector<int>(p.size()));
		for (int i=0; i < s.size(); i++) {
			if (i) for (int j=0; j<p.size(); j++) pref[i][j] += pref[i-1][j];
			for (int j=0; j<p.size() and i+j < s.size(); j++) {
				if (s[i+j] != p[j]) break;
				pref[i+j][j]++;
			}
		}
		vector<ll> ptot;
		ptot.push_back(pref[0][p.size()-1]);
		for (int i=1; i<s.size(); i++) ptot.push_back(ptot.back() + pref[i][p.size()-1]);

		reverse(s.begin(), s.end());
		reverse(p.begin(), p.end());	
		vector suf(s.size(), vector<int>(p.size()));
		for (int i=0; i < s.size(); i++) {
			if (i) for (int j=0; j<p.size(); j++) suf[i][j] += suf[i-1][j];
			for (int j=0; j<p.size() and i+j < s.size(); j++) {
				if (s[i+j] != p[j]) break;
				suf[i+j][j]++;
			}
		}
		vector<ll> stot;
		stot.push_back(suf[0][p.size()-1]);
		for (int i=1; i<s.size(); i++) stot.push_back(stot.back() + suf[i][p.size()-1]);
		
		reverse(suf.begin(), suf.end());
		for (auto &u : suf) reverse(u.begin(), u.end());
		reverse(stot.begin(), stot.end());

		int n = s.size();
		while (q--) {
			int l, r; cin >> l >> r; l--, r--;
			ll p1 = ptot[l] * ll(n-r); 
			ll s1 = stot[r] * ll(l+1);
			ll ans = p1 + s1;
			for (int i=1; i<p.size(); i++) {
				ans += pref[l][i-1] * (ll) suf[r][i];	
			}
			ll den = ll(n-r) * (l+1);
			ll g = gcd(den, ans);
			ans /= g, den /= g;
			cout << ans << "/" << den << endl;
		}

	}
	
	
	exit(0);
}
