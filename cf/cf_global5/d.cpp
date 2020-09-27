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

template<typename T> struct rmq {
	vector<T> v;
	int n, b;
	vector<int> id, st;
	vector<vector<int>> table;
	vector<vector<vector<int>>> entre;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	rmq() {}
	rmq(vector<T>& v_) {
		v = v_, n = v.size();
		b = (__builtin_clz(1)-__builtin_clz(n)+1)/4 + 1;
		id.resize(n);
		table.assign(4*b, vector<int>((n+b-1)/b));
		entre.assign(1<<b<<b, vector<vector<int>>(b, vector<int>(b, -1)));
		for (int i = 0; i < n; i += b) {
			int at = 0, l = min(n, i+b);
			st.clear();
			for (int j = i; j < l; j++) {
				while (st.size() and op(st.back(), j) == j) st.pop_back(), at *= 2;
				st.push_back(j), at = 2*at+1;
			}
			for (int j = i; j < l; j++) id[j] = at;
			if (entre[at][0][0] == -1) for (int x = 0; x < l-i; x++) {
				entre[at][x][x] = x;
				for (int y = x+1; y < l-i; y++)
					entre[at][x][y] = op(i+entre[at][x][y-1], i+y) - i;
			}
			table[0][i/b] = i+entre[at][0][l-i-1];
		}
		for (int j = 1; (1<<j) <= (n+b-1)/b; j++)
			for (int i = 0; i+(1<<j) <= (n+b-1)/b; i++)
				table[j][i] = op(table[j-1][i], table[j-1][i+(1<<(j-1))]);
	}
	T query(int i, int j) {
		if (i/b == j/b) return v[i/b*b+entre[id[i]][i%b][j%b]];
		int x = i/b+1, y = j/b-1, ans = i;
		if (x <= y) {
			int t = __builtin_clz(1) - __builtin_clz(y-x+1);
			ans = op(ans, op(table[t][x], table[t][y-(1<<t)+1]));
		}
		ans = op(ans, op(i/b*b+entre[id[i]][i%b][b-1], j/b*b+entre[id[j]][0][j%b]));
		return v[ans];
	}
};

rmq<int>R;
int bb(int l, int r, int x){
//	cout << l << " lr " << r << endl;
	if(l>=r) return l;
	int m = (l+r)/2;
	int q = R.query(l, m);
//	cout << "q " << q << endl;
	if(q< (x+1)/2) r = m;
	else l = m+1; 
	return bb(l, r, x);
}

int main(){ _
	int n; cin >> n;
	vector<int> v;
	int maxi = 0;
	int id=0;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
		if(a>maxi) id = i, maxi = a;
	}
	for(int i=0;i <2*n; i++) v.pb(v[i]);
	id+=n;
	R = rmq<int> (v);
	vector<int> ans(n), dp(n);
	
	int mini= bb(id+1, v.size()-1, maxi);
	if(mini==v.size()-1){
		for(int i=0;i <n; i++) cout << -1 << " ";
		cout << endl;
		exit(0);
	}

	dp[id%n]=mini;
	ans[id%n] = mini-id;
	for(int i=1; i<n; i++){
		id--;
	//	if(v[id]<v[id+1]){
	//		ans[id] = ans[id+1]; continue;
	//	}
		
		mini = bb(id+1, dp[(id+1)%n], v[id]);
		ans[id%n] = mini-id;
		dp[id%n]=mini;
	}

	for(int i=0;i <n; i++) cout << ans[i] << " ";
	cout << endl;
	exit(0);
}

