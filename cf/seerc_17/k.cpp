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
	vector<int> v;
	
	vector<int> ans(n);
	vector<vector<int>> pos(n);
	for(int i=0;i <n; i++) {
		int a; cin >> a;
		a--;
		v.pb(a);
		pos[a].pb(i);
	}

	int ptr = n;
	for(int i=0; i<n; i++){
		for(auto u : pos[i]) ans[u] = ptr--;
	}
	for(auto u : ans) cout << u << " ";
	cout << endl;
	
	
	
	exit(0);
}
