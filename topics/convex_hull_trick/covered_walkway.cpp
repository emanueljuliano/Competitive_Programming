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


int main(){ _
	int n; ll c; cin >> n >> c;

	vector<ll> v(n);
	for(auto &i : v) cin >> i;

	vector<pair<ll, ll>> w(n);

	auto cost = [&](int i, int j){
		ll d = w[i].f - w[j].f;
		return w[i].s + d*d;
	};
	auto f = [&](int i1, int i2, int i3){
		// prev1 + (x-x1)^2 -> x^2 + (x1^2 + prev1) - 2*x*x1
		// l1 =  -2*x*x1 + x^2 + (x1^2 + prev1)
		// l2 =  -2*x*x2 + x^2 + (x2^2 + prev2)
		// l3 =  -2*x*x3 + x^2 + (x3^2 + prev3)
		// if (inter(l1, l3) < inter(l1, l2)), erase l2
		// x*a1 + b1 = x*a3 + b3
		// x = (b3-b1)/(a1-a3)
		// erase if (b3-b1)/(a1-a3) < (b2-b1)/(a1-a2)
		ll a1 = -2*w[i1].f, b1 = w[i1].f*w[i1].f + w[i1].s;
		ll a2 = -2*w[i2].f, b2 = w[i2].f*w[i2].f + w[i2].s;
		ll a3 = -2*w[i3].f, b3 = w[i3].f*w[i3].f + w[i3].s;
		
		return (b3-b1)*(a1-a2) <= (b2-b1)*(a1-a3);
	};

	int l = 0, r = 0;
	ll ans = 0;
	for(int i=0;i <n; i++){
		int old_r = r;
		w[old_r] = {v[i], ans+c};
		while(r-l>=2 and f(r-2, r-1, old_r)) r--;
		w[r++] = {v[i], ans+c};
		
		while(r>l+1 and cost(l, r-1) >= cost(l+1, r-1)) l++;
		ans = cost(l, r-1);
	}
	cout << ans << endl;

	exit(0);
}
