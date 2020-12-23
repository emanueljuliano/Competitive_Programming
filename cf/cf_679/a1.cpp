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

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		vector<int> ans(n);
		for(int i=0;i <n/2; i++) ans[i] = v[n-1-i];
		for(int i=n/2;i<n; i++) ans[i] = -v[n-1-i];
		for(auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
