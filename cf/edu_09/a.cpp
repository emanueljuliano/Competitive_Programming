#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, p; cin >> n >> p;
	
	vector<string> v(n);
	for (auto &s : v) cin >> s;
	ll at = 0, ans = 0;
	for (int i=n-1; i+1; i--) {
		if (v[i] == "half") ans += at*p, at*=2;
		else if(v[i] == "halfplus") ans += at*p+p/2, at*=2, at++;
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
