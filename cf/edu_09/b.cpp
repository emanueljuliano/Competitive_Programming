#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v(n); 
	for(auto &i : v) cin >> i;
	string s; cin >> s;
	ll a = 0, b = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A') a+= v[i];
		else b += v[i];
	}

	// suf
	ll ans = b, at = b;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A') at += v[i];
		else at -= v[i];
		ans = max(ans, at);
	}
	at = b;
	for (int i=n-1; i+1; i--) {
		if (s[i] == 'A') at += v[i];
		else at -= v[i];
		ans = max(ans, at);
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
