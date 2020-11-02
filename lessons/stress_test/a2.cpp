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


int main(){ _
	int n, m, a, d; cin >> n >> m >> a >> d;

	vector<int> v(m);
	for(auto &i : v) cin >> i;
	for(int i=1; i<=n; i++)
		v.pb(i*a);
	
	sort(v.begin(), v.end());
	int last = 0, ans = 0;

	for(auto t : v){
		if(t<=last) continue;
		ans++;
		last = t+d;
	}

	cout << ans << endl;
		
	exit(0);
}
