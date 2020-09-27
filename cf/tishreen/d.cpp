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
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> gg(n), gb(n);
		for(int i=0; i<m; i++){
			int a, b; cin >> a >> b; a--, b--;
			gb[a] |= 1<<b; 
			gg[b] |= 1<<a; 
		}

		int ans = n;
		for(int i=0;i <(1<<n); i++){
			int at = __builtin_popcount(i);	
			int at2 = at;
			for(int j=0; j<n; j++){
				if((gb[j]&i) == i) at++;
				if((gg[j]&i) == i) at2++;
			}
			ans = max({ans, at, at2});
		}
		cout << ans << endl;
	}

	exit(0);
}
