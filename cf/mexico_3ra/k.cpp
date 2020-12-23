#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

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

const int MAX = 3e5+10;

mint fact[MAX];

mint binom(int n, int k){
    if (k > n) return 0;
    return fact[n]/(fact[k]*fact[n-k]);
}

int main() { _
    int t;
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = i*fact[i-1];
    while (t--){
        int A, B, C, K, c;
        cin >> A >> B >> C >> K >> c;
        if (B < A) swap(B, A);

        int k = K-c;
        if (k <= 0 or k>A+B){
            cout << 0 << endl;
			continue;
        }
        int X = B+A;

        mint ans = binom(X, k) - binom(A, 0)*binom(B, k) - binom(A, k)*binom(B, 0);
        ans *= binom(C, c);
        cout << ans << endl;
    }
	exit(0);
}
