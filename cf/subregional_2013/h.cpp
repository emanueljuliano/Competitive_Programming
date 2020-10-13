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

const int MOD = 1e6;
ll mod(ll v){ return (v + MOD) % MOD; }
ll sum(ll l, ll r){ return mod(l+r); }
ll mult(ll l, ll r){ return mod(l*r); }
bool equal(ll l, ll r){ return mod(l-r) == 0; }

template<typename T> struct matrix {
	vector<vector<T>> in;
	int row, col;

	void print(){//
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				cout << in[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int row, int col, int op = 0):row(row), col(col), in(row, vector<T>(col, 0)){
		if (op) for (int i = 0; i < row; i++) in[i][i] = 1;
	}
	matrix(initializer_list<initializer_list<T>> c):
		row(c.size()), col((*c.begin()).size()){
			in = vector<vector<T>>(row, vector<T>(col, 0));
			int i, j;
			i = 0;
			for (auto &it : c){
				j = 0;
				for (auto &jt : it){
					in[i][j] = jt;
					j++;
				}
				i++;
			}
		}
	T &operator()(int i, int j){ return in[i][j]; }
	//in case of a transposed matrix, swap i and j
	matrix<T>& operator*=(T t){
		matrix<T> &l = *this;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				l(i, j) = mult(l(i, j), t); //% MOD) % MOD;
		return l;
	}
	matrix<T> operator+(matrix<T> &r){
		matrix<T> &l = *this;
		matrix<T> m(row, col, 0);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				m(i, j) = sum(l(i, j), r(i, j)); //% MOD) % MOD;
		return m;
	}
	matrix<T> operator*(matrix<T> &r){
		matrix<T> &l = *this;
		int row = l.row;
		int col = r.col;
		int K = l.col;
		matrix<T> m(row, col, 0);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				for (int k = 0; k < K; k++)
					m(i, j) = sum(m(i, j), mult(l(i, k), r(k, j)));
		return m;
	}
	matrix<T> operator^(long long e){
		matrix<T> &m = (*this);
		if (e == 0) return matrix(m.row, m.row, 1);
		if (e == 1) return m;
		if (e == 2) return m*m;
		auto m_ = m^(e/2); m_ = m_*m_;
		if (e%2 == 1) m_ = m_ * m;
		return m_;
	}
	void multiply_r(int i, T k){
		matrix<T> &m = (*this);
		for (int j = 0; j < col; j++)
			m(i, j) = mult(m(i, j), k);
	}
	void multiply_c(int j, T k){
		matrix<T> &m = (*this);
		for (int i = 0; i < row; j++)
			m(i, j) = mult(m(i, j), k);
	}
};

int main(){ _
	ll n, k, l; cin >> n >> k >> l;
	n/=5LL;

	// rec(i) = k*rec(i-1) + l*rec(i-2)
	matrix<ll> M(2, 2);
	M(0, 0) = k%MOD, M(0, 1) = l%MOD;
	M(1, 0) = 1, M(1, 1) = 0;
	matrix<ll> v(2, 1);
	v(0, 0) = 1, v(1, 0) = 0;
	matrix<ll> ans(2, 1);
	ans = (M^n)*v;
	ll ret = ans(0, 0);
	
	ll at = MOD;
	for(int i= 6; i; i--){
		ret = ret%at;
		at/=10;
		cout << ret/at;
	}
	cout << endl;
	exit(0);
}
