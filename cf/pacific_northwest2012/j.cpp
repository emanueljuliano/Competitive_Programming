#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10;
const double eps = 1e-7;

long long a, b, c, x, y, z;
vector<ll> v;
ll dp[MAX];
double H;
#define sq(x) ll(x)*(x)

double base(ll h){
	return (H-(a-h))*b/H;
}

ll area(ll h, ll k){
	ll num = base(h)/k;
	num *= num;
	return num*k*k*k;
}

ll solve(ll h){
	if(h < 0) return -LINF;
	ll &ret = dp[h];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i <3; i++){
		ret = max(ret, solve(h-v[i]) + area(h-v[i], v[i]));
	}
	return ret;
}

ll solve2(ll h){
	if(h < 0) return -LINF;
	ll &ret = dp[h];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i <3; i++){
		ret = max(ret, solve(h-v[i]) + sq(b/v[i])*sq(v[i])*v[i]);
	}
	return ret;
}

int main(){ _
		
	v.resize(3);
	while(cin >> a >> b >> c >> x >> y >> z){
		for(int i=0;i <=a; i++) dp[i] = -1;
		if(b<c) swap(b, c);
		if(b==c){
			cout << solve2(a) << endl;
			continue;
		}
		H = a*b/double(b-c);
		v[0] = x, v[1] = y, v[2] = z;
		cout << solve(a) << endl;
	}	
	
	exit(0);
}
