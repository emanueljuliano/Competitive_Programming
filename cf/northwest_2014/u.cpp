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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<string, int> mp;
		vector<ii> pos;
		int ptr = 0;
		vector<ii> ev;
		for(int i=0;i <n; i++){
			string s; cin >> s;
			ev.pb({i, ptr});
			mp[s] = ptr++;
		}
		for(int i=0;i <n; i++){
			string s; cin >> s;
			ev.pb({i, mp[s]});
		}
		sort(ev.begin(), ev.end());
		vector<int> vis(n);
		int sz = 0, at = 0;
		vector<int> ans;
		
		int x = -1;
		for(auto p : ev){
			int cur = p.s, xx = p.f;
			if(vis[cur]) at--;
			else vis[cur]=1, at++;
			if(xx==x) sz++;

			if(at==0){
				ans.pb(sz);
				sz = 0;
			}
			x = xx;
		}
		for(int i=0;i <ans.size(); i++){
			cout << ans[i];
			if(i!=ans.size()-1) cout << " ";
		}
		cout << endl;

	
	
	}
	
	
	
	exit(0);
}
