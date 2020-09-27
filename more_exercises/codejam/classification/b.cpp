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
		string ans;
		s.pb('0');
		int op = 0;
		for(int i=0; i<s.size(); i++){
			if(op<s[i]-'0'){
				for(op; op<s[i]-'0'; op++)
					ans.pb('(');
				}
			else if(op>s[i]-'0')
				for(op; op>s[i]-'0'; op--){
					ans.pb(')');
				}
			ans.pb(s[i]);
		}
		ans.pop_back();
		cout << "Case #" << cs << ": " << ans << endl;
	}
	
	
	
	exit(0);
}
