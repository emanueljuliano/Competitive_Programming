#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


const int MAX = 110;

int M[MAX][MAX];

int main(){ _
	memset(M, -1, sizeof M);
	int n, m; cin >> n >> m;
	for (int i=0;i <n; i++) {
		int q; cin >> q;
		for (int j=0; j<q; j++) {
			int a, b; cin >> a >> b; a--;
			M[i][a] = b;
		}
	}
	
	for (int i=0; i<n; i++) {
		int mini = INF, st = -1;
		for (int j=0; j<n; j++) {
			if (i == j) continue;
			int dist = 0;
			int commom = 0;
			for (int k=0; k<m; k++) {
				if (M[i][k] != -1 and M[j][k] != -1) 
					dist += (M[i][k] - M[j][k]) * (M[i][k] - M[j][k]), commom++;
			}
			if (!commom) dist = INF-1;
			if (dist < mini) mini = dist, st = j;
		}
		int maxi = -1, sub = -2;
		for (int k=0; k<m; k++) {
			if (M[i][k] == -1 and M[st][k] > maxi) sub = k, maxi = M[st][k];	
		}
		cout << sub+1 << endl;
	}
	
	
	exit(0);
}
