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
	vector<vector<int>> v(4);
	int n; cin >> n;
	for(int i=0;i <n; i++){
		string s; int a;
		cin >> s >> a;
		if(s=="00") v[0].pb(a);
		if(s=="01") v[1].pb(a);
		if(s=="10") v[2].pb(a);
		if(s=="11") v[3].pb(a);
	}
	for(int i=0;i <4; i++) sort(v[i].begin(), v[i].end(), greater<>());
	
	int ans = 0;
	for(auto u : v[3]) ans+=u;
	int mini = min(v[2].size(), v[1].size());
	for(int i=0;i <mini; i++) ans += v[1][i]+v[2][i];

	vector<int> res;
	for(int i=0; i<v[0].size(); i++) res.pb(v[0][i]);
	for(int i=mini; i<v[1].size(); i++) res.pb(v[1][i]);
	for(int i=mini; i<v[2].size(); i++) res.pb(v[2][i]);

	sort(res.begin(), res.end(), greater<>());
	for(int i=0; i<min(v[3].size(), res.size()); i++) ans += res[i];

	cout << ans << endl;

	
	exit(0);
}
