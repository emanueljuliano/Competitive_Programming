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
	while(true){
		int n; string s; cin >> n >> s;
		if(!n) break;
		bool com = false;
		string ans;
		for(int i=0;i <s.size(); i++){
			if(s[i]-'0' != n){
				if(s[i] != '0') com = true;
				if(com) ans+=s[i];
			}
		}
		if(ans.empty()) cout << 0 << endl;
		else cout << ans << endl;
	}	
	
	
	
	exit(0);
}
