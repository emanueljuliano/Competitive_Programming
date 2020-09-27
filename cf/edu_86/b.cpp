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
		string s; cin >> s;
		string ans;
		bool flag = false;
		for(int i=0;i <s.size(); i++){
			if(s[i] != s[0]) flag = true;
		}
		if(!flag)cout << s << endl;
		else{
			if(s[0]=='0'){
				for(int i=0;i <s.size(); i++){
					ans.pb('0');
					ans.pb('1');
				}
			}
			else{
				for(int i=0;i <s.size(); i++){
					ans.pb('1');
					ans.pb('0');
				}

			}
			cout << ans << endl;	
		}
	
	}
	
	
	
	exit(0);
}
