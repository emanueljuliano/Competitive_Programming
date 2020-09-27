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

ll rec(ll n, ll m){
	if(n<1) return 0;
	if(n==1) return m+1;
	return 2*n+2*m-2 + rec(n-2, m-2);
}

int main(){ _
	ll n, m; cin >> n >> m;
	if(n>m) swap(n, m);
	cout << rec(n, m) << endl;
	
	
	
	exit(0);
}
