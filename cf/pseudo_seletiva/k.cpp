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
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0;i <n; i++){
		ans = max(ans, min(v[i]-1, (int)1e6-v[i]));
	}
	cout << ans << endl;
	
	
	
	exit(0);
}