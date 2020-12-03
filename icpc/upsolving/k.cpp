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

const int MAX = 110;

vector<int> basis[MAX]; // basis[i] = mask do cara com bit mais significativo i
int rk; // tamanho da base

void insert(vector<int> v) {
	for (int i = MAX - 1; i >= 0; i--) if (v[i]) {
		if (basis[i].empty()) {
			basis[i] = v, rk++;
			return;
		}
		for(int j=0; j<MAX; j++) v[j]^=basis[i][j];
	}
}

int A[MAX][MAX];
int dg[MAX];

int main(){ _
	int n, m; cin >> n >> m;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		A[a][b]=1, A[b][a] = 1;
		dg[a]++;
		dg[b]++;
	}

	for(int i=0;i <n; i++){
		vector<int> v(MAX);
		for(int j=0;j <MAX; j++) v[j] = A[i][j];
		v[i] = dg[i]%2;
		insert(v);
	}

	int at = rk;
	vector<int> v(MAX);
	for(int i=0; i<n; i++) v[i] = (dg[i]+1)%2;
	insert(v);
	if(rk != at) cout << "N" << endl;
	else cout << "Y" << endl;
	
	
	
	exit(0);
}
