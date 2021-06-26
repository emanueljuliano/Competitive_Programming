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
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		k = (n+k-1)/k*k;
		int geq = (k+n-1)/n;
		cout << geq << endl;

	}
	
	
	
	exit(0);
}
