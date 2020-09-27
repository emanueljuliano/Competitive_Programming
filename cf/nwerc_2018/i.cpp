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
	for(auto &i:v) cin >> i;
	sort(v.begin(), v.end());
	double ans = 2;
	for(int i=0;i <n; i++){
		int u = v[i];
		if(u>i+1) return cout << -1 << endl, 0;
		ans = min(ans, double(u)/(i+1));
	}
	cout << setprecision(6) << fixed;
	cout << ans << endl;
	
	
	
	exit(0);
}
