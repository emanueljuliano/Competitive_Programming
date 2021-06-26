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

const int MAX = 2002;
using bit = bitset<MAX+1>;

bit basis[MAX], solve[MAX];
int id[MAX];
int rk, n;

void insert(bit mask, int line = -1){
	if(line==-1) line = rk;
	bit cur; cur[rk] = 1;
	for(int i=n-1; i>=0; i--) if(mask[i]){
		if(basis[i] == 0){
			basis[i] = mask, rk++;
			solve[i] = cur, id[rk-1] = line;
			return;
		}
		mask ^= basis[i], cur ^= solve[i];
	}
}

vector<int> get(bit mask){
	vector<int> ret;
	bit cur = 0;
	for(int i=n-1; i>=0; i--) if(mask[i]){
		if(basis[i] == 0) return {-1};
		mask ^= basis[i];
		cur ^= solve[i];
	}
	for(int i=0; i<n; i++) if(cur[i]) ret.push_back(id[i]);
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int m; cin >> n >> m;
		vector<bit> M(n);
		vector<int> dg(n);
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			dg[a]++, dg[b]++;
			M[a][b] = 1;
			M[b][a] = 1;
		}
		bool unique = true;
		for(int i=0;i <n; i++) if(dg[i]%2) M[i][i] = 1, unique = false;

		if(unique){
			cout << 1 << endl;
			for(int i=0;i <n; i++) cout << 1 << " ";
			cout << endl;
		}
		else{
			for(int i=0;i <n; i++) for(int j=0; j<n; j++) basis[i][j] = 0;
			rk = 0;
			bit y;
			for(int i=0;i <n; i++) insert(M[i], i);
			for(int i=0;i <n; i++) y[i]=dg[i]%2;
			vector<int> ret = get(y);
			vector<int> ans(n, 1);
			for(auto u : ret) ans[u]++;
			cout << 2 << endl;
			for(auto u : ans) cout << u << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
