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

const ll MOD = 998244353;
ll inv(ll a, ll b=MOD) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll mod(ll v){ return (v + MOD) % MOD; }
ll sum(ll l, ll r){ return mod(l+r); }
ll mult(ll l, ll r){ return mod(l*r); }
ll inverse(ll l){ return inv(l, MOD); }
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

	matrix(int row_, int col_, int op = 0):row(row_), col(col_), in(row_, vector<T>(col_, 0)){
		if (op) for (int i = 0; i < row_; i++) in[i][i] = 1;
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
	void sum_r(int i1, int i2, T k){
		matrix<T> &m = (*this);
		for (int j = 0; j < col; j++)
			m(i1, j) = sum(m(i1, j), mult(k, m(i2, j)));

	}
	bool gaussian(int I, int J){
		matrix<T> &m = (*this);
		T tmp = m(I, J);
		if (equal(tmp, 0)) return false;
		multiply_r(I, inverse(tmp));
		for (int i = 0; i < row; i++)
			if (i != I) sum_r(i, I, mult(-1, m(i, J)));
		multiply_r(I, tmp);
		return true;
	}
};

int main(){ _
	int n, m; cin >> n >> m;
	
	vector<vector<int>> gt(n), mex(n);
	vector<int> grundy(n), dg(n);
	vector<ll> cnt(2*(n+m)+100);
	for(int i=0;i <n; i++) mex[i].pb(0);

	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		mex[a].pb(0), gt[b].pb(a);
		dg[a]++;
	}

	queue<int> q;
	for(int i=0;i <n; i++) if(!dg[i]) q.push(i);
	int sz = 0;

	while(q.size()){
		int x = q.front(); q.pop();	
		for(int i=0;i <mex[x].size(); i++) if(!mex[x][i]){
			sz=max(sz, i), grundy[x] = i, cnt[i]++; 
			break;
		}
		for(auto u : gt[x]) {
			dg[u]--;
			if(grundy[x]<mex[u].size()) mex[u][grundy[x]] = 1;
			if(!dg[u]) q.push(u);
		}
	}
	
	// P_v = sum P_to * cnt(to^v)/(n+1) + (v!=0)/(n+1)
	sz = 2*sz;
	matrix<ll> M(sz+2, sz+2);
	for(int i=0;i <=sz; i++){
		for(int j=0;j <=sz; j++) M(i, j) = (ll)cnt[j^i]*inv(n+1)%MOD;
		
		M(i, i) = sum(M(i, i), -1);
		if(i) M(i, sz+1) = mod(-inv(n+1));
	}
	for(int i=0;i <=sz; i++) M.gaussian(i, i);	
	ll ans = M(0, sz+1)*inv(M(0, 0))%MOD;
	cout << ans << endl;
	
	
	exit(0);
}
