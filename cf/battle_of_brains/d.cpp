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
	int cs = 0;
	while(t--){
		cs++;
		string s; cin >> s;
		string ans = s;
		if(s.size()>1) for(int i=2;i <=s.size(); i++){
			ans.pb(s[s.size()-i]);
		}
		cout << "Case " << cs << ": "  << ans << endl;
	}
	
	exit(0);
}
