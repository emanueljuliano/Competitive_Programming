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
	int n, m; cin >> n >> m;
	ll ans = 0;
	int maxi = -1;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		int b = m-a;
		if(ans==-1) continue;

		if(min(a, b) >= maxi) maxi = min(a, b), ans += min(a, b);
		else if(max(a, b) >=maxi) maxi = max(a, b), ans+=max(a, b);
		else ans = -1;
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
