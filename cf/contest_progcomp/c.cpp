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
	int n; cin >> n;
	
	vector<int> factor;
	for(int i=2; i*i<=n; i++) while(n%i==0){
		factor.pb(i);
		n/=i;
	}
	if(n!=1) factor.pb(n);
	ll at = 1;
	ll ans = 1;
	for(int i=factor.size()-1; i+1; i--){
		at *= factor[i];
		ans += at;
	}
	cout << ans << endl;

	
	
	
	exit(0);
}
