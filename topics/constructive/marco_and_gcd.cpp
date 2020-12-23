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
	vector<int> v(n);
	int g = 0;
	for(auto &i : v) cin >> i, g = gcd(i, g);
	if(g != v[0]) return cout << -1 << endl, 0;
	cout << 2*n << endl;
	for(auto u : v) cout << u << " " << g << " ";
	cout << endl;	
	
	
	exit(0);
}
