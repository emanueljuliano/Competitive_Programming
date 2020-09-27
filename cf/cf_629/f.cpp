// Teste 2
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
const int MAX = 2e5+10;
vector<ll> v;

ll seg[4*MAX], lazy[4*MAX];
int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		int m = (l+r)/2;
		seg[2*p] += lazy[p]*(m-l+1);
		seg[2*p+1] += lazy[p]*(r-(m+1)+1);
		lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] += (ll)x*(r-l+1);
			lazy[p] += x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}


int main(){ _
		
	ll k; cin >> n >> k;
	for(int i=0; i<n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	sort(v.begin(), v.end());
	int ig=1, iat=1;
	for(int i=0; i<n; i++){
		if(v[i]==v[i+1]) iat++;
		else{
			ig = max(ig, iat);
			iat = 1;
		}
	}
	if(ig>=k){
		cout << 0 << endl;
		exit(0);
	}
	build();
	ll ans = query(0, n-1);
	for(ll i=0; i <n; i++){
		ll at;
		//cout <<"TIME" << endl;
		//cout << v[i] << endl;

		update(0, i-1, -v[i]);
		at = -query(0, i-1);
		update(0, i-1, v[i]);
		//cout << "at1 " <<" " << at << endl;

		update(i+1, n-1, -v[i]);
		at += query(i+1, n-1);
		update(i+1, n-1, v[i]);
		
		if(at>=(n-k)) at -= (n-k);
		ans = min(ans, at);
		//cout << "at2 " <<" " << at << endl;

		if(i<=n-k){
			update(i+1, n-1, -v[i]);
			at = query(i+1, n-1);
			if(at>=(n-k-i)) at -= (n-k-i);
			//cout << "at3 " <<" " << at << endl;
			ans = min(ans, at);
			update(i+1, n-1, v[i]);
		}
		if(i>=k-1){
			update(0, i-1, -v[i]);
			at = -query(0, i-1);
			if(at>=(i+1-k)) at -= (i+1-k);
			//cout << "at4 " <<" " << at << endl;
			ans = min(ans, at);
			update(0, i-1, v[i]);
		}
	}
	cout << ans << endl;
	
	exit(0);
}
