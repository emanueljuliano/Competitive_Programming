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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		int ans = INF;
		for(int i=1; i<=100; i++) {
			int at = 0;
			for(int j=0; j<n; j++){
				if(v[j] != i) at++, j+=k-1;
			}
			ans = min(ans, at);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
