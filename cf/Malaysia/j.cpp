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
	vector<vector<char>> bf(6);
	for(int i=0;i <5; i++){
		string s; cin >> s;
		int a = s[0]-'A', b = s[2]-'A';
		char c = s[1];

		if(c=='<') bf[b].pb(a);
		else bf[a].pb(b);
	}	

	vector<int> ans;
	set<int> vis;
	int sz = 0;
	while(ans.size()<5){
		sz = ans.size();
		for(int i=0;i <5; i++) if(!vis.count(i)){
			bool show = true;
			for(auto u : bf[i]) if(!vis.count(u)) show=false;
			if(!show) continue;
			ans.pb(i);
			vis.insert(i);
		}
		if(ans.size() ==sz) break;
	}
	if(ans.size()<5) return cout << "impossible" << endl, 0;
	else for(auto u : ans) cout << char(u+'A');
	cout << endl;
	
	
	exit(0);
}
