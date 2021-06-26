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
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		int ans = 0;
		for(int i=1; i<n; i++) ans = max(ans, v[i]-v[i-1]);

		int at = INF;
		for(int i=0; i<n-2; i++){
			at = min(at, v[i+2]-v[i]);
		}
		ans = max(ans, at);
		cout << ans << endl;
	
	
	
	exit(0);
}
