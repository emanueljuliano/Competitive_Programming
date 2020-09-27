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
	int n, m, x; cin >> n >> m >> x;
	int ans = 0;
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			int a; cin >> a;
			ans += (__gcd(x, a)>1);
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
