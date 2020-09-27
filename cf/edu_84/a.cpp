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
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		ll an= 2*k-3;
		n -= (an+1)*(k-1)/2;
		if(n%2 and n>an) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
