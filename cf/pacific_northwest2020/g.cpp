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
		char c; int t, m, a; cin >> c >> t >> m >> a;
		
		if(c=='h'){
			ev.pb({{t-a, 1}, i});
			ev.pb({{t-a+m, -1}, i});
		}
		else{
			ev.pb({{t-a, 2}, i});
			ev.pb({{t-a+m, -2}, i});
		}
	}
	sort(ev.begin(), ev.end());
	set<int> sh, sv;
	ll ans = 0;
	for(auto IT : ev){
		int t = IT.f.f, flag = IT.f.s, id=IT.s;

		if(flag==1) sh.insert(id), ans += sv.size();
		else if(flag==2) sv.insert(id), ans += sh.size();
		else if(flag==-1) sh.erase(id);
		else if(flag==-2) sv.erase(id);
	}
	cout << ans << endl;
	
	
	exit(0);
}
