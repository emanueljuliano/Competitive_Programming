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
		vector<string> ans;
		string s; cin >> s;
		for(int i=0;i <s.size(); i++) if(s[i]!='0'){
			string at; at+= s[i];
			for(int j=i+1; j<s.size(); j++){
				at += '0';
			}
			ans.pb(at);
		}	
		cout << ans.size() << endl;
		for(auto k : ans) cout << k << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
