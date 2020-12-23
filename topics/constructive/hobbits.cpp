#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
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

	int ans = 2;
	while(ans*(ans+1)/2 <= n) ans++;
	
	vector<vector<int>> v(ans);
	int at = 1;
	for(int i=0;i <ans; i++) for(int j=i+1; j<ans; j++) v[i].pb(at), v[j].pb(at++);

	cout << ans << endl;
	for(auto u : v) {
		for(auto x : u) cout << x << " ";
		cout << endl;
	}	
	exit(0);
}
