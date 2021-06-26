#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		string s; cin >> s;	
		vector<pair<int, char>> v;
		int it = 0;
		while(it<s.size()){
			int at = 1;
			char c = s[it];
			while(it<s.size()-1 and s[it]==s[it+1]) it++, at++;
			v.pb({at, c});
			it++;
		}
		int ans = 0;
		vector<int> used(v.size());
		for(int i=0;i <v.size(); i++){
			ans += v[i].f - (v[i].f + 2)/3;
			if(i<int(v.size()-2) and v[i+1].f==1 and v[i].s==v[i+2].s){
				if(v[i].f%3==0 or v[i+2].f%3==0) continue;
				if(v[i].f%3==1 and used[i]) continue;
				if(v[i].f%3==2 and !used[i]) continue;
				if(v[i+2].f%3==2) {used[i+2]=true; continue;}
				if(v[i+2].f%3==1) used[i+2]=true;
				ans++;
			}
		}
		cout << ans << endl;

	}
	
	
	
	exit(0);
}
