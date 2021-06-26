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
	vector<int> v(3);
	for(auto &u : v) cin >> u;

	int maxi = 0;
	maxi = max(maxi, v[0]+v[1]+v[2]);
	maxi = max(maxi, v[0]+v[1]*v[2]);
	maxi = max(maxi, v[0]*v[1]+v[2]);
	maxi = max(maxi, v[0]*v[1]*v[2]);
	maxi = max(maxi, (v[0]+v[1])*v[2]);
	maxi = max(maxi, v[0]*(v[1]+v[2]));

	cout << maxi << endl;
	
	exit(0);
}
