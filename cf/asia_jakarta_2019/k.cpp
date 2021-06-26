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

template<int p> struct mod_int {
	ll pow(ll b, ll e) {
		if (e == 0) return 1;
		ll r = pow(b*b%p, e/2);
		if (e%2 == 1) r = (r*b)%p;
		return r;
	}
	ll inv(ll b) { return pow(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p || v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator+=(const m &a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator-=(const m &a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator*=(const m &a) {
		v = (v*ll(a.v))%p;
		return *this;
	}
	m& operator/=(const m &a) {
		v = (v*inv(a.v))%p;
		return *this;
	}
	m operator-(){ return m(-v); }
	m& operator^=(ll e) {
		if (e < 0){
			v = inv(v);
			e = -e;
		}
		v = pow(v, e%(p-1));
		return *this;
	}
	bool operator==(const m &a) { return v == a.v; }
	bool operator!=(const m &a) { return v != a.v; }

	friend istream &operator>>(istream &in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream &operator<<(ostream &out, m a) {
		return out << a.v;
	}
	friend m operator+(m a, m b) { return a+=b; }
	friend m operator-(m a, m b) { return a-=b; }
	friend m operator*(m a, m b) { return a*=b; }
	friend m operator/(m a, m b) { return a/=b; }
	friend m operator^(m a, ll e) { return a^=e; }

	static m rt(bool f, int n, int N){
		if (p == 998244353){
			m r(102292); // an element of order N
			int ord = (1 << 23);
			while (ord != N){
				r = r*r;
				ord /= 2;
			}
			if (f) r = r^(-1);
			return r^(N/n);
		}
		return -1;
	}
};

typedef mod_int<(int)1e9+7> mint;


typedef tuple<mint, mint, mint, mint, int> T;

const int MAX = 1e5+10;
string s;
namespace seg {
	T seg[4*MAX];
	bool lazy[4*MAX];
	int n;

	T comb(T f, T g){
		auto [faa, fab, fba, fbb, rf] = f;
		auto [gaa, gab, gba, gbb, rg] = g;
		if(rf) swap(faa, fbb), swap(fba, fab);
		if(rg) swap(gaa, gbb), swap(gba, gab);
		// ga(fa, fb), gb(fa, fb)
		// ga(fa, fb) = gaa*fa + gab*fb
		T ret =  T(
			gaa*faa + gab*fba,
			gaa*fab + gab*fbb,
			gba*faa + gbb*fba,
			gba*fab + gbb*fbb,
			0
		);
		return ret;
	}
	T build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) seg[p] = s[l]=='A' ? T(1, 1, 0, 1, 0) : T(1, 0, 1, 1, 0);
		else{
			int m = (l+r)/2;
			seg[p] = comb(build(2*p, l, m), build(2*p+1, m+1, r));
		}
		//cout << "range " << l << " " << r << endl;
		//auto [faa, fab, fba, fbb, rev] = seg[p];
		//cout << "fa = (" << faa << ", " << fab << ") fb = (" << fba << ", " << fbb << ")" << endl;

		return seg[p];
	}
	void prop(int p, int l, int r) {
		get<4>(seg[p]) ^= lazy[p];
		if (l != r) lazy[2*p] ^= lazy[p], lazy[2*p+1] ^= lazy[p];
		lazy[p] = 0;
	}
	T query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {1, 0, 0, 1, 0};
		int m = (l+r)/2;
		return comb(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	T update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = 1;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = comb(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

int main(){ _
	int n, q; cin >> n >> q;
	cin >> s;
	seg::n = n;
	seg::build();
	while(q--){
		int f; cin >> f;
		if(f==1){
			int l, r; cin >> l >> r; l--, r--;
			seg::update(l, r, 1);
		}
		else{
			int l, r; mint a, b; cin >> l >> r >> a >> b; l--, r--;
			T qu = seg::query(l, r);
			auto [faa, fab, fba, fbb, rev] = qu;
			if(rev) swap(faa, fbb), swap(fba, fab);
			//cout << "fa = (" << faa << ", " << fab << ") fb = (" << fba << ", " << fbb << ")" << endl;
			mint aux = faa*a + fab*b;
			b = fba*a + fbb*b;
			a = aux;
			cout << a << " " << b << endl;
		}
	}
	
	
	exit(0);
}
