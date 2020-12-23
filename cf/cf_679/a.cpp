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

vector<int> w;
vector<int> v(6);

int main(){ _
	for(auto &i : v) cin >> i;
	int n; cin >> n;
	w.resize(n);
	for(auto &i : w) cin >> i;
	sort(w.begin(), w.end());

	vector<ii> pos;
	for(auto a : v) for(int i=0;i <n; i++) pos.pb({w[i]-a, i});
	sort(pos.begin(), pos.end());
	
	vector<int> vis(n);
	int r = 0; vis[0] = 1;
	while(pos[r].s!=n-1) ++r, vis[pos[r].s]++;
	int ans = pos[r].f - pos[0].f;
	for(int l=0;l <pos.size(); l++){
		vis[pos[l].s]--;
		if(!vis[pos[l].s]){
			while(r<pos.size()-1 and pos[r].s!=pos[l].s) ++r, vis[pos[r].s]++;
			if(!vis[pos[l].s]) break;
		}
		ans = min(ans, pos[r].f - pos[l+1].f);
	}
	
	cout << ans << endl;
	
	
	exit(0);
}
