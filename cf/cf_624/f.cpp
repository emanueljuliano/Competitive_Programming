#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 202345;
int n;
ll t[4*N];
ll query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr)
		 + query(2*i+1, m+1, r, ql, qr);
}
void update(int i, int l, int r, int p, ll x) {
	if (l == r) {
		t[i] += x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = t[2*i] + t[2*i+1];
	}
}

ll t2[4*N];
ll query2(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t2[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query2(2*i, l, m, ql, qr)
		 + query2(2*i+1, m+1, r, ql, qr);
}
void update2(int i, int l, int r, int p, ll x) {
	if (l == r) {
		t2[i] += x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update2(2*i, l, m, p, x);
		else update2(2*i+1, m+1, r, p, x);
		t2[i] = t2[2*i] + t2[2*i+1];
	}
}

bool ord(ii a, ii b){
	return a.s<b.s;
}

int main(){ _
	memset(t, 0, sizeof(t));
	memset(t2, 0, sizeof(t2));
	cin >> n;
	vector<ll> v;
	vector<ii> w;
	ll a;
	for(int i=0; i<n; i++) cin >> a, v.pb(a);
	for(int i=0; i<n; i++) cin >> a, w.pb({v[i], a});

	sort(w.begin(), w.end(), ord);
	map<ll, int> ma;
	for(int i=0; i<n; i++) ma[w[i].s] = i;
	
	sort(w.begin(), w.end());
	ll ans = 0;
	for(int i=0; i<n; i++){
		int x = ma[w[i].s];
		ll cnt= query(1, 0, n-1, 0, x);
		ll sum = query2(1, 0, n-1, 0, x);
		
		ans += w[i].f * cnt - sum;
		update(1, 0, n-1, x, 1);
		update2(1, 0, n-1, x, w[i].f);
	}
	
	cout << ans << endl;

	exit(0);
}
