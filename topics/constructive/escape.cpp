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

double eps = 1e-8;

int main(){ _
	int v1, v2, t, f, c; cin >> v1 >> v2 >> t >> f >> c;
	if(v1>=v2) return cout << 0 << endl, 0;
	double p = v1*t;
	int ans = 0;
	while(p+eps<c){
		double time = p/double(v2-v1);
		double np = time*v2;
		if(np+eps >= c) break;
		p = np + np/v2*v1 + f*v1;
		ans++;
	}
	cout << ans << endl;
	
	
	exit(0);
}
