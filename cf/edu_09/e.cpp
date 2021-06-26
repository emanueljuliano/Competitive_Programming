#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct cplx{
	double r, i;
	cplx(complex<double> c):r(c.real()), i(c.imag()){}
	cplx() : r(0), i(0){}
	cplx(double r_, double i_ = 0):r(r_), i(i_){}
	double abs(){ return hypot(r, i); }
	double abs2(){ return r*r + i*i; }
	cplx inv() { return cplx(r/abs2(), i/abs2()); }
	cplx& operator+=(cplx a){
		r += a.r; i += a.i;
		return *this;
	}
	cplx& operator-=(cplx a){
		r -= a.r; i -= a.i;
		return *this;
	}
	cplx& operator*=(cplx a){
		double r_ = r*a.r - i*a.i;
		double i_ = r*a.i + i*a.r;
		r = r_;
		i = i_;
		return *this;
	}
	cplx conj(){
		return cplx(r, -i);
	}
	cplx& operator/=(cplx a){
		auto a_ = a.inv();
		return (*this)*=a_;
	}
	cplx operator-(){ return cplx(-r, -i); }
	cplx& operator^=(double e){
		return *this = pow(complex<double>(r, i), e);
	}
	friend ostream &operator<<(ostream &out, cplx a){
		return out << a.r << " + " << a.i << "i";
	}
	friend cplx operator+(cplx a, cplx b){ return a+=b; }
	friend cplx operator-(cplx a, cplx b){ return a-=b; }
	friend cplx operator*(cplx a, cplx b){ return a*=b; }
	friend cplx operator/(cplx a, cplx b){ return a/=b; }
	friend cplx operator^(cplx a, double e){ return a^=e; }

	//fft
	static int fft_len(int N){
		int n = 1, log_n = 0;
		while (n <= N) { n <<= 1; log_n++; }
		return log_n;
	}
	static cplx rt(bool f, int n, int N){
		const static double PI = acos(-1);
		double alpha = (2*PI)/n;
		if (f) alpha = -alpha;
		return cplx(cos(alpha), sin(alpha));
	}
};


template<typename T> void fft(vector<T> &a, bool f, int N, vector<int> &rev){
	for (int i = 0; i < N; i++)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	int l, r, m;
	vector<T> roots(N);
	for (int n = 2; n <= N; n *= 2){
		T root = T::rt(f, n, N);
		roots[0] = 1;
		for (int i = 1; i < n/2; i++)
			roots[i] = roots[i-1]*root;
		for (int pos = 0; pos < N; pos += n){
			l = pos+0, r = pos+n/2, m = 0;
			while (m < n/2){
				auto t = roots[m]*a[r];
				a[r] = a[l] - t;
				a[l] = a[l] + t;
				l++; r++; m++;
			}
		}
	}
	if (f) {
		auto invN = T(1)/N;
		for(int i = 0; i < N; i++) a[i] = a[i]*invN;
	}
}

template<typename T> vector<T> convolution(vector<T> &a, vector<T> &b) {
	vector<T> l(a.begin(), a.end());
	vector<T> r(b.begin(), b.end());
	int ln = l.size(), rn = r.size();
	int N = ln+rn+1;
	int n = 1, log_n = 0;
	while (n <= N) { n <<= 1; log_n++; }
	vector<int> rev(n);
	for (int i = 0; i < n; ++i){
		rev[i] = 0;
		for (int j = 0; j < log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1 << (log_n-1-j);
	}
	assert(N <= n);
	l.resize(n);
	r.resize(n);
	fft(l, false, n, rev);
	fft(r, false, n, rev);
	for (int i = 0; i < n; i++)
		l[i] *= r[i];
	fft(l, true, n, rev);
	for (auto &i : l) i = i.r > 0.5 ? 1 : 0;
	while (l.size() and l.back().r == 0) l.pop_back();
	return l;
}

int main(){ _
	int n, k; cin >> n >> k;
	vector<cplx> v(1001);
	for (int i=0;i <n; i++) {
		int a; cin >> a;
		v[a] = 1;
	}	
	
	vector<cplx> ret(1, 1);
	while (k) {
		if (k & 1) ret = convolution(ret,  v);
		k >>= 1;
		if(k) v = convolution(v,  v);
	}
	for (int i=0;i <ret.size(); i++) if(ret[i].r == 1) cout << i << " ";
	cout << endl;

	exit(0);
}

