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


typedef mint ld;

ld eps = 1e-10;
ld coef(ii a, ii b){
	return (b.s-a.s)/ld(b.f-a.f);
}

int main(){ _
	int n; cin >> n;
	
	vector<ii> v(n+1);
	vector<ld> l(n);
	vector<int> a(n);
	for(auto &i : v) cin >> i.f >> i.s;
	for(int i=0;i <n-1; i++){
		ld l1 = coef(v[i+2], v[i+1]) - coef(v[i+1], v[i]);
		l1 /= 2.0;
		a[i] = v[i+1].f;
		l[i] = l1;
		//cout << "l = " << l[i] << " a[i] = " << a[i] << endl;
	}

	vector<ld> pl, pa;
	pl.pb(0), pa.pb(0);
	for(int i=0;i <n; i++) pl.pb(pl.back() + l[i]), pa.pb(pa.back() + a[i]*l[i]);

	bool ans = true;
	//cout << "pontos " << endl;
	for(int i=0;i <n+1; i++){
		int x = v[i].f;
		ld y = pa[n]-2*pa[i] - (pl[n]-2*pl[i])*x;	
		//cout << "(" << x << ", " <<y  << ") (" << v[i].f << ", " << v[i].s << ")" << endl;
		if(y!=v[i].s) ans = false;
	}
	
	{
		ld c = coef(v[n-1], v[n]);
		ld b = v[n].s - c*v[n].f;
		int x_inf = 1e6+10;
		ld y_input = x_inf*c + b;
		ld y_nosso = x_inf*pl[n] - pa[n];	
		if(y_input != y_nosso) ans = false;
	}
	{
		ld c = coef(v[1], v[0]);
		ld b = v[0].s - c*v[0].f;
		int x_inf = -1e6-10;
		ld y_input = x_inf*c + b;
		ld y_nosso = pa[n] - x_inf*pl[n];	
		if(y_input != y_nosso) ans = false;
	}


	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;

	
	
	exit(0);
}
