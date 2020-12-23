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

int M[111][111];
int main(){ 
	int n; cin >> n;
	int a, b;
	int maxi = 0;
	while(cin >> a >> b){
		M[a][b]^=1;
		M[b][a]^=1;
		maxi = max(maxi, a);
		maxi = max(maxi, b);
	}
	for(int i=1; i<=maxi; i++) {for(int j=1; j<=maxi; j++) cout << M[i][j] << " "; cout << endl;}
	
	
	exit(0);
}
