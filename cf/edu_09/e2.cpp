#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6+10;

const ld tau = 2*acos(-1);

inline complex<ld> unity_root(int n, bool inv) { // unity_root(n)^n = (e^(2.pi.i/n))^n = 1
	return polar<ld>(1.0, (inv ? -1 : 1) * tau / n);
}

template<typename T> void fft(vector<T>& a, bool inv) {
	for(int i = 1, j = 0; i < a.size(); i++) { // reverse bit order
		int bit = a.size() / 2;
		while (j & bit) j ^= bit, bit /= 2;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}

	for (int n = 2; n <= a.size(); n *= 2) {
		vector<T> roots(n/2);
		T omega = unity_root(n, inv);
		roots[0] = 1;
		for (int i = 1; i < n/2; i++) roots[i] = roots[i-1] * omega;
		for (int i = 0; i < a.size(); i += n) {
			int l = i, r = i + n/2;
			for (int j = 0; j < n/2; j++, l++, r++) {
				T t = roots[j] * a[r];
				a[r] = a[l] - t, a[l] = a[l] + t;
			}
		}
	}
}

template<typename T> vector<T> convolution(vector<T> A, vector<T> B) {
	int n = 1;
	while (n < A.size()+B.size()) n<<=1;
	//n = 1 << (__builtin_clz(1) - __builtin_clz(n) + (n & (n - 1) ? 1 : 0)); // log ceil
	A.resize(n), B.resize(n);

	fft(A, false), fft(B, false);
	vector<T> C(n);

	for (int i = 0; i < n; i++) C[i] = A[i] * B[i];

	fft(C, true);
	for (auto& c : C) c /= n;

	for (auto &i : C) i = i.real() > 0.5 ? 1 : 0;
	while (C.back().real() == 0) C.pop_back();
	return C;
}

typedef complex<ld> mint;

vector<mint> v(int(1e3)+1);

int main(){ _
	int n, k; cin >> n >> k;
	
	for (int i=0;i <n; i++) {
		int a; cin >> a;
		v[a] = 1;
	}	
	
	vector<mint> ret(1);
	ret[0] = 1;
	while (k) {
		if (k & 1) ret = convolution(ret,  v);
		k >>= 1;
		if (k != 0) v = convolution(v,  v);
	}
	for (int i=0;i <ret.size(); i++) if(ret[i].real() == 1) cout << i << " ";
	cout << endl;

	exit(0);
}

