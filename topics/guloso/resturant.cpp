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

bool cmp(ii a, ii b){
	return a.s < b.s;
}

int main(){ _
	int n; cin >> n;
	vector<ii> v;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		v.pb({a, b});
	}
	sort(v.begin(), v.end(), cmp);

	int at = -1;
	int ans = 0;
	for(int i=0;i <n; i++){
		if(v[i].f<=at) continue;
		ans++;
		at = v[i].s;
	}
	cout << ans << endl;
	
	
	
	
	exit(0);
}
