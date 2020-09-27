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
	vector<pair<ii, int>> ev;
	for(int i=0;i <n; i++){
		int x0, y0, x1, y1, x2, y2; cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		int y = max({y0, y1, y2});
		int yy = min({y0, y1, y2});
		ev.pb({{yy, 0}, i});
		ev.pb({{y, 1}, i});
	}
	sort(ev.begin(), ev.end());
	int it = 0;
	set<int> st;
	int ans = 0;
	for(auto IT : ev){
		int flag = IT.f.s, id = IT.s, y=IT.f.f;
		if(flag==0){
			st.insert(id);
			ans = max(ans, (int)st.size());
		}
		else{
			st.erase(id);
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
