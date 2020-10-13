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
#define sq(x) ((ll)x)*(x)

int x;


ll val(int a, int b, int c){
	return sq(a) + sq(b) + sq(c) + (ll)7*min({a, b, c});
}

ll solve(int a, int b, int c, int d){
	if(d==0) return val(a, b, c);

	ll ret = 0;
	ret = max(ret, solve(a+1, b, c, d-1));
	ret = max(ret, solve(a, b+1, c, d-1));
	ret = max(ret, solve(a, b, c+1, d-1));
	return ret;
}
int main(){ _
		
	int t; cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		cin >> x;
		if(c<b) swap(b, c);
		if(c<a) swap(a, c);

		if(x<=14) cout << solve(a, b, c, x) << endl;
		else cout << val(a, b, c+x) << endl;
	}

	exit(0);
}
