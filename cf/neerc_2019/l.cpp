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

const int MAX = 2005;
using bit = bitset<MAX>;
bit basis[MAX];
bit solve[MAX];
bit zero;
int rk, n;
int id[MAX];

void insert(bit mask, int x){
	for(int i=n-1; i>=0; i--) if(mask[i]){
		if(basis[i] == zero){
			basis[i] = mask, rk++;
			id[i] = x;
			return;
		}
		mask ^= basis[i];
	}
}

bool can;
bit get(bit mask){
	bit ret = 0;
	for(int i=n-1; i>=0; i--) if(mask[i]){
		if(basis[i] == 0) {can = false; return ret;}
		mask ^= basis[i], ret[i] = 1;
	}
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
		bit y;
		for(int i=0;i <n; i++) if(dg[i]%2) M[i][i] = 1, y[i] = 1, unique = false;

		for(int i=0;i <n; i++) {
			for(int j=0;j <n; j++) cout << M[i][j] << " ";
			cout << endl;
		}
		for(int i=0;i <n; i++) cout << y[i] << " ";
		cout << endl;
		

		if(unique){
			cout << 1 << endl;
			for(int i=0;i <n; i++) cout << 1 << " ";
			cout << endl;
		}
		else{
			for(int i=0;i <n; i++) for(int j=0; j<n; j++) basis[i][j] = 0;
			rk = 0;
			can = true;
			vector<int> ans(n);

			for(int i=0;i <n; i++) insert(M[i], i);
			for(int i=0;i <n; i++) y[i]=dg[i]%2;
			bit ret = get(y);
			assert(can);
			cout << 2 << endl;
			for(int i=0;i <n; i++) cout << ret[i]+1 << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
