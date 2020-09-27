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


int main(){ _
	int n; cin >> n;
	int M[(int)1e3+10][(int)1e3+10];
	for(int i=0; i<n; i++){
		for(int j=0;j <n; j++){
			cin >> M[i][j];
		}
	}
	ll a1a2 = M[0][1];
	ll a2a3 = M[1][2];
	ll a1a3 = M[0][2];
	ll a11 = a1a2*a1a3/a2a3;
	vector<int> ans;
	ll a1 = 1; while(a1*a1!=a11) a1++;
	ans.pb(a1);
	for(int i=1; i<n; i++){
		ans.pb(M[0][i]/a1);
	}
	for(auto k : ans) cout << k<< " ";
	cout << endl;

	exit(0);
}
