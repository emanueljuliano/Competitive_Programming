#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;

struct bint {
	static const int BASE = 1e9;
	vector<int> v;
	bool neg;

	bint() : neg(0) {}
	bint(int val) : bint() { *this = val; }
	bint(long long val) : bint() { *this = val; }

	void trim() {
		while (v.size() and v.back() == 0) v.pop_back();
		if (!v.size()) neg = 0;
	}

	// converter de/para string | cin/cout
	bint(const char* s) : bint() { from_string(string(s)); }
	bint(const string& s) : bint() { from_string(s); }
	void from_string(const string& s) {
		v.clear(), neg = 0;
		int ini = 0;
		while (ini < s.size() and (s[ini] == '-' or s[ini] == '+' or s[ini] == '0'))
			if (s[ini++] == '-') neg = 1;
		for (int i = s.size()-1; i >= ini; i -= 9) {
			int at = 0;
			for (int j = max(ini, i - 8); j <= i; j++) at = 10*at + (s[j]-'0');
			v.push_back(at);
		}
		if (!v.size()) neg = 0;
	}
	string to_string() {
		if (!v.size()) return "0";
		string ret;
		if (neg) ret += '-';
		for (int i = v.size()-1; i >= 0; i--) {
			string at = ::to_string(v[i]);
			int add = 9 - at.size();
			if (i+1 < v.size()) for (int j = 0; j < add; j++) ret += '0';
			ret += at;
		}
		return ret;
	}
	friend istream& operator>>(istream& in, bint& val) {
		string s; in >> s;
		val = s;
		return in;
	}
	friend ostream& operator<<(ostream& out, bint val) {
		string s = val.to_string();
		out << s;
		return out;
	}

	// operators
	friend void swap(bint& a, bint& b) { swap(a.v, b.v), swap(a.neg, b.neg); }
	friend bint min(const bint& a, const bint& b) { return (a < b) ? a : b; }
	friend bint max(const bint& a, const bint& b) { return a < b ? b : a; }
	friend bint abs(bint val) {
		val.neg = 0;
		return val;
	}
	friend bint operator-(bint val) {
		if (val != 0) val.neg ^= 1;
		return val;
	}
	bint& operator=(const bint& val) { v = val.v, neg = val.neg; return *this; }
	bint& operator=(long long val) {
		v.clear(), neg = 0;
		if (val < 0) neg = 1, val *= 1;
		for (; val; val /= BASE) v.push_back(val % BASE);
		return *this;
	}
	int cmp(const bint& r) { // menor: -1 | igual: 0 | maior: 1
		if (neg != r.neg) return neg ? -1 : 1;
		if (v.size() != r.v.size()) {
			int ret = v.size() < r.v.size() ? -1 : 1;
			return neg ? -ret : ret;
		}
		for (int i = int(v.size())-1; i >= 0; i--) {
			if (v[i] != r.v[i]) {
				int ret = v[i] < r.v[i] ? -1 : 1;
				return neg ? -ret : ret;
			}
		}
		return 0;
	}
	bool operator<(const bint& r) { return cmp(r) == -1; }
	bool operator>(const bint& r) { return cmp(r) == 1; }
	bool operator<=(const bint& r) { return cmp(r) <= 0; }
	bool operator>=(const bint& r) { return cmp(r) >= 0; }
	bool operator==(const bint& r) { return cmp(r) == 0; }
	bool operator!=(const bint& r) { return cmp(r) != 0; }
	template<typename T> bool friend operator<(T l, bint r){ return bint(l) < r; }
	template<typename T> bool friend operator>(T l, bint r){ return bint(l) > r; }
	template<typename T> bool friend operator<=(T l, bint r){ return bint(l) <= r; }
	template<typename T> bool friend operator>=(T l, bint r){ return bint(l) >= r; }
	template<typename T> bool friend operator==(T l, bint r){ return bint(l) == r; }
	template<typename T> bool friend operator!=(T l, bint r){ return bint(l) != r; }
	bint& operator +=(const bint& r) {
		if (!r.v.size()) return *this;
		if (neg != r.neg) return *this -= -r;
		for (int i = 0, c = 0; i < r.v.size() or c; i++) {
			if (i == v.size()) v.push_back(0);
			v[i] += c + (i < r.v.size() ? r.v[i] : 0);
			if ((c = v[i] >= BASE)) v[i] -= BASE;
		}
		return *this;
	}
	friend bint operator+(bint a, const bint& b) { return a += b; }
	bint& operator -=(const bint& r) {
		if (!r.v.size()) return *this;
		if (neg != r.neg) return *this += -r;
		if ((!neg and *this < r) or (neg and r < *this)) {
			*this = r - *this;
			neg ^= 1;
			return *this;
		}
		for (int i = 0, c = 0; i < r.v.size() or c; i++) {
			v[i] -= c + (i < r.v.size() ? r.v[i] : 0);
			if ((c = v[i] < 0)) v[i] += BASE;
		}
		trim();
		return *this;
	}
	friend bint operator-(bint a, const bint& b) { return a -= b; }

	// operators de * / %
	bint& operator *=(int val) {
		if (val < 0) val *= -1, neg ^= 1;
		for (int i = 0, c = 0; i < v.size() or c; i++) {
			if (i == v.size()) v.push_back(0);
			long long at = (long long) v[i] * val + c;
			v[i] = at % BASE;
			c = at / BASE;
		}
		trim();
		return *this;
	}
	friend bint operator *(bint a, int b) { return a *= b; }
	friend bint operator *(int a, bint b) { return b *= a; }
	using cplx = complex<double>;
	void fft(vector<cplx>& a, bool f, int N, vector<int>& rev) {
		for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
		vector<cplx> roots(N);
		for (int n = 2; n <= N; n *= 2) {
			const static double PI = acos(-1);
			for (int i = 0; i < n/2; i++) {
				double alpha = (2*PI*i)/n;
				if (f) alpha = -alpha;
				roots[i] = cplx(cos(alpha), sin(alpha));
			}
			for (int pos = 0; pos < N; pos += n)
				for (int l = pos, r = pos+n/2, m = 0; m < n/2; l++, r++, m++) {
					auto t = roots[m]*a[r];
					a[r] = a[l] - t;
					a[l] = a[l] + t;
				}
		}
		if (!f) return;
		auto invN = cplx(1)/cplx(N);
		for (int i = 0; i < N; i++) a[i] *= invN;
	}
	vector<long long> convolution(const vector<int>& a, const vector<int>& b) {
		vector<cplx> l(a.begin(), a.end()), r(b.begin(), b.end());
		int ln = l.size(), rn = r.size(), N = ln+rn+1, n = 1, log_n = 0;
		while (n <= N) n <<= 1, log_n++;
		vector<int> rev(n);
		for (int i = 0; i < n; i++) {
			rev[i] = 0;
			for (int j = 0; j < log_n; j++) if (i>>j&1)
				rev[i] |= 1 << (log_n-1-j);
		}
		l.resize(n), r.resize(n);
		fft(l, false, n, rev), fft(r, false, n, rev);
		for (int i = 0; i < n; i++) l[i] *= r[i];
		fft(l, true, n, rev);
		vector<long long> ret;
		for (auto& i : l) ret.push_back(round(i.real()));
		return ret;
	}
	vector<int> convert_base(const vector<int>& a, int from, int to) {
		static vector<long long> pot(10, 1);
		if (pot[1] == 1) for (int i = 1; i < 10; i++) pot[i] = 10*pot[i-1];
		vector<int> ret;
		long long at = 0;
		int digits = 0;
		for (int i : a) {
			at += i * pot[digits];
			digits += from;
			while (digits >= to) {
				ret.push_back(at % pot[to]);
				at /= pot[to];
				digits -= to;
			}
		}
		ret.push_back(at);
		while (ret.size() and ret.back() == 0) ret.pop_back();
		return ret;
	}
	bint operator*(const bint& r) { // O(n log(n))
		bint ret;
		ret.neg = neg ^ r.neg;
		auto conv = convolution(convert_base(v, 9, 4), convert_base(r.v, 9, 4));
		long long c = 0;
		for (auto i : conv) {
			long long at = i+c;
			ret.v.push_back(at % 10000);
			c = at / 10000;
		}
		for (; c; c /= 10000) ret.v.push_back(c%10000);
		ret.v = convert_base(ret.v, 4, 9);
		if (!ret.v.size()) ret.neg = 0;
		return ret;
	}
	bint& operator*=(const bint& r) { return *this = *this * r; };
	bint& operator/=(int val) {
		if (val < 0) neg ^= 1, val *= -1;
		for (int i = int(v.size())-1, c = 0; i >= 0; i--) {
			long long at = v[i] + c * (long long) BASE;
			v[i] = at / val;
			c = at % val;
		}
		trim();
		return *this;
	}
	friend bint operator/(bint a, int b) { return a /= b; }
	int operator %=(int val) {
		if (val < 0) val *= -1;
		long long at = 0;
		for (int i = int(v.size())-1; i >= 0; i--)
			at = (BASE * at + v[i]) % val;
		if (neg) at *= -1;
		return at;
	}
	friend int operator%(bint a, int b) { return a %= b; }
	friend pair<bint, bint> divmod(const bint& a_, const bint& b_) { // O(n^2)
		if (a_ == 0) return {0, 0};
		int norm = (BASE-1) / b_.v.back();
		bint a = abs(a_) * norm;
		bint b = abs(b_) * norm;
		bint q, r;
		for (int i = a.v.size() - 1; i >= 0; i--) {
			r *= BASE, r += a.v[i];
			long long upper = b.v.size() < r.v.size() ? r.v[b.v.size()] : 0;
			int lower = b.v.size() - 1 < r.v.size() ? r.v[b.v.size() - 1] : 0;
			int d = (upper * BASE + lower) / b.v.back();
			r -= b*d;
			while (r < 0) r += b, d--; // roda O(1) vezes
			q.v.push_back(d);
		}
		reverse(q.v.begin(), q.v.end());
		q.neg = a_.neg ^ b_.neg;
		r.neg = a_.neg;
		q.trim(), r.trim();
		return {q, r / norm};
	}
	bint operator/(const bint& val) { return divmod(*this, val).first; }
	bint& operator/=(const bint& val) { return *this = *this / val; }
	bint operator%(const bint& val) { return divmod(*this, val).second; }
	bint& operator%=(const bint& val) { return *this = *this % val; }
};

/*
#define ll bint
ll choice(ll a, ll b){ // a!/b!/(a-b)!
	if(a<b) return 0;
	ll ret = 1;
	for(int i=1;i <=a; i++) ret*=i;
	for(int i=1;i <=b; i++) ret/=i;
	for(int i=1;i <=a-b; i++) ret/=i;
	return ret;
}
*/

//typedef long long ll;
typedef bint ll;

ll choice(int a, int b){
	if(a<b) return 0;
	vector<int> v(a+10), w(a+10);
 
	ll ret = 1;
	for(int j=2;j <=a; j++){
		ret *= j;
		for(int i=2;i <=b; i++) if(ret%i==0 and !v[i]) ret/=i, v[i]=1;
		for(int i=2;i <=a-b; i++) if(ret%i==0 and !w[i]) ret/=i, w[i]=1;
	}
	return ret;
}

vector<long long> v, pref;
ll ret = 0;
void solve(long long at, int k, int pos){
	while(true){
		if(!k) {ret=ret+1; return;}
		if(v[0]>=at) return;
		bool show = false;
		for(int i=0;i <pos; i++) if(v[i]<at and v[i+1]>=at){
			ret = ret+choice(i, k);
			at = at-v[i], k=k-1, pos = i-1, show = true;
			break;
		}
		if(!show) ret = ret+choice(pos, k), at-=v[pos], k-=1, pos-=1;
	}
}

int main(){ _
	int n, k; cin >> n >> k;
	v.resize(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	int a, b; cin >> a >> b;
	ll r1;
	solve(b+1, k, n-1);
	r1 = ret, ret = 0;
	solve(a, k, n-1);
	ll ans = r1-ret;
	cout << ans << endl;
	exit(0);
}
