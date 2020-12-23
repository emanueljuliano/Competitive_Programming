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

int main(){ 
	freopen("equal.in", "r", stdin); _	
	int t; cin >> t;
	while(t--){
		int a, b, c; cin >> a >> b >> c;
		bool ans = (a==b) or (a==c) or (b==c);
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	exit(0);
}
