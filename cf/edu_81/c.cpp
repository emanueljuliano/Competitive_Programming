#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int tc; cin >> tc;
	while(tc--){
		string s; cin >> s;
		string t; cin >> t;
	
		set<char> se, te;
		vector<vector<int>> vs(30);
		for(int i=0; i<s.size(); i++){
		vs[s[i]-'a'].pb(i);
		}

		int at = -1;
		int ans = 1;
		for(int i=0; i<t.size(); i++){
			int c = t[i]-'a';
			if(vs[c].empty()){
				ans = -1;
				break;
			}
			int upp =  upper_bound(vs[c].begin(), vs[c].end(), at) - vs[c].begin();
		//	cout << c << " " << at << " " << upp << endl;
			if(upp==vs[c].size()){
				at = -1;
				ans++;
				upp =  upper_bound(vs[c].begin(), vs[c].end(), at) - vs[c].begin();
				at = vs[c][upp];
			}
			else{
				at = vs[c][upp];
			}
		}
		cout << ans << endl;
	}


	exit(0);
}
