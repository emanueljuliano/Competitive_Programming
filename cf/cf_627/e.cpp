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

int n, mod, l, r;
vector<int> v;

int pd[2020][2020];

int rec(int pos, int p){
	if(pos>=n) return 0;
	int &ans = pd[pos][p];
	if(ans != -1) return ans;

	for(int i=0;i <2; i++){
		int at = (p+v[pos]-i)%mod;
		ans = max(ans, rec(pos+1, at) + (at>=l and at<=r));
	}
	return ans;
}

int main(){ _
	memset(pd, -1, sizeof(pd));
	cin >> n >> mod >> l >> r;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		v.pb(a);
	}
	int ans = rec(0, 0);
	cout << ans << endl;
	
	
	exit(0);
}
