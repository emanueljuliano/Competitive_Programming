#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
#define MODULAR true
template<typename T> struct matrix : vector<vector<T>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int n_, int m_, bool ident = false) :
		vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
			if (ident) {
				assert(n == m);
				for (int i = 0; i < n; i++) (*this)[i][i] = 1;
			}
		}
	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
	n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<T>>& c) {
		vector<vector<T>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	matrix<T> operator*(matrix<T>& r) {
		assert(m == r.n);
		matrix<T> M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				T add = (*this)[i][k] * r[k][j];
#if MODULAR
				M[i][j] += add%MOD;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
#else
				M[i][j] += add;
#endif
			}
		return M;
	}
	matrix<T> operator^(ll e){
		matrix<T> M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
	void apply_transform(matrix M, ll e){
		auto& v = *this;
		while (e) {
			if (e&1) v = M*v;
			e >>= 1;
			M = M*M;
		}
	}
};

void solve3(int n, int m) {
	auto mapping = [&](int x, int y){
		return x + (y << 3);
	};

	auto valid = [&](int x, int y, int z){
		if (x == 7 or y == 7 or z == 7) return 0;

		for (int i = 0; i < 3; i++)
			if (x>>i&1 and y>>i&1 and z>>i&1) return 0;

		// diagonais
		if (x>>0&1 and y>>1&1 and z>>2&1) return 0;
		if (x>>2&1 and y>>1&1 and z>>0&1) return 0;

		x ^= 7;
		y ^= 7;
		z ^= 7;

		if (x == 7 or y == 7 or z == 7) return 0;

		for (int i = 0; i < 3; i++)
			if (x>>i&1 and y>>i&1 and z>>i&1) return 0;

		// diagonais
		if (x>>0&1 and y>>1&1 and z>>2&1) return 0;
		if (x>>2&1 and y>>1&1 and z>>0&1) return 0;

		return 1;
	};


	auto valid_col = [&](int x, int y){
		return x != 7 && y != 7 && x != 0 && y != 0;
	};

	int dim = mapping(0b111, 0b111);

	matrix<ll> trans(dim+1, dim+1);
	for (int a = 0; a < (1 << 3); a++){
		for (int b = 0; b < (1 << 3); b++){
			int row = mapping(a, b);
			for (int x = 0; x < (1 << 3); x++){
				for (int y = 0; y < (1 << 3); y++){
					if (!valid(x, y, a) || !valid(y, a, b)) continue;
					int col = mapping(x, y);
					trans[row][col] = 1;
				}
			}
		}
	}

	int e = (m-1)/2;


	matrix<ll> init(dim+1, 1);

	if (m%2 == 0){
		for (int a = 0; a < (1 << 3); a++){
			for (int b = 0; b < (1 << 3); b++){
				if (valid_col(a, b)) init[mapping(a, b)][0] = 1;
			}
		}
		trans = trans^(e);
	}
	else{
		for (int y = 0; y < (1 << 3); y++){
			for (int a = 0; a < (1 << 3); a++){
				for (int b = 0; b < (1 << 3); b++){
					if (valid(y, a, b)) init[mapping(a, b)][0]++;
				}
			}
		}
		trans = trans^(e-1);
	}


	auto v = trans*init;

	ll ans = 0;
	for (int a = 0; a < (1 << 3); a++){
		for (int b = 0; b < (1 << 3); b++){
			ans += v[mapping(a, b)][0];
			if (ans >= MOD) ans -= MOD;
		}
	}
	cout << ans << endl;
}

int main() { _
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (n > m) swap(n, m);
		
		if (n >= 5) cout << 8 << endl;
		else if (n == 4) {
			if (m == 4) cout << 18 << endl;
			else cout << 14 << endl;
		}
		else if (n == 3) {
			solve3(n, m);
		}
		else if (n == 2) {
			/*
				2 2 -1
				1 0 0
				0 1 0
			*/
			matrix<ll> M(3, 3);
			M[0][0] = 2, M[0][1] = 2, M[0][2] = -1;
			M[1][0] = 1, M[1][1] = 0, M[1][2] = 0;
			M[2][0] = 0, M[2][1] = 1, M[2][2] = 0;
			matrix<ll> v(3, 1);
			v[0][0] = 100, v[1][0] = 36, v[2][0] = 16;
			auto ans = (M^(m-2))*v;
			cout << ans[2][0] << endl;
		}
		else if (n == 1) {
			/*
				1 1
				1 0
			*/
			matrix<ll> M(2, 2);
			M[0][0] = 1, M[0][1] = 1;
			M[1][0] = 1, M[1][1] = 0;
			matrix<ll> v(2, 1);
			v[0][0] = 4, v[1][0] = 2;
			auto ans = (M^(m-1))*v;
			cout << ans[1][0] << endl;
		}
	}
	
	exit(0);
}
