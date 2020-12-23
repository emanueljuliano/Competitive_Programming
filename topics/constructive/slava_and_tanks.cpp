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
	vector<int> ans;
	for(int i=2; i<=n; i+=2) ans.pb(i);
	for(int i=1; i<=n; i+=2) ans.pb(i);
	for(int i=2; i<=n; i+=2) ans.pb(i);
	cout << ans.size() << endl;
	for(auto u : ans) cout << u << " ";
	cout << endl;

	exit(0);
}
