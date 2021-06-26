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
		int n, m; cin >> n >> m;
		vector<int> v(n); for(auto &i : v) cin >> i;
		vector<int> w(m); for(auto &i : w) cin >> i;
		
		int ans = 0;
		for(int i=0;i <n; i++){
			int p =upper_bound(w.begin(), w.end(), v[i]) - lower_bound(w.begin(), w.end(), v[i]);
			ans += p;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
