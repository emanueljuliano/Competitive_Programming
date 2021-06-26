#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int, int> T;

const int INF = 5e5+10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 5e5+10;
ll n; 	
vector<int> v;
T seg[4*MAX];


T merge(T a, T b){
	auto [a1, a2, a3, a4] = a;
	auto [b1, b2, b3, b4] = b;
	T ret = {max({a1+b2, a3+b1, a1, b1}),
			max({a2+b2, a4+b1, a2, b2}), 
			max({a1+b4, a3+b3, a3, b3}),
			max({a2+b4, a4+b3, a4, b4})};
	
	return ret;
}

T build(int p, int l, int r){
	if(l==r){
		if(v[l]>0) return seg[p] = {1, 0, 0, -INF};
		else if(v[l]==0) return seg[p] = {-INF, 0, 0, -INF};
		else return seg[p] = {-INF, 0, 0, 1};
	}
	int m = (l+r)/2;
	return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
}

T update(int pos, T x, int p=1, int l=0, int r=n-1){
	if(r < pos or pos < l) return seg[p];
	if(l==r) return seg[p] = x;
	int m = (l+r)/2;
	return seg[p] = merge(update(pos, x, 2*p, l, m), update(pos, x, 2*p+1, m+1, r));
}

int main(){ _
	ll x, y;
	cin >> n >> x >> y;
	v.resize(n);
	for(auto &i : v) cin >> i;
	
	vector<ii> ev;
	for(int i=0;i <n; i++) ev.pb({abs(v[i]), i});
	sort(ev.begin(), ev.end());
	
	auto val = [&](){
		auto [u1, u2, u3, u4] = seg[1];
		ll ret = max({u1, u2, u3, u4});
		ret = n-ret;
		return ret*y;
	};

	build(1, 0, n-1); // seg that returns the biggest alternating sequence
	ll ans = val();
	for(auto [u, id] : ev){ // try to use u+1 fake accounts
		update(id, {1, 0, 0, 1});
		ans = min(ans, val()+(u+1)*x);
	}
	cout << ans << endl;
	exit(0);
}
