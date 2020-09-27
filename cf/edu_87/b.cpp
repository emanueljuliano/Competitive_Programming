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
		int a=-1, b=-1, c=-1;
		string s; cin >> s;
		int ans = INF;
		for(int i=0;i <s.size(); i++){
			if(s[i]=='1') a=i;
			else if(s[i]=='2') b = i;
			else if(s[i]=='3') c = i;
			if(a!=-1 and b!=-1 and c!=-1) ans = min(ans, i+1-min({a, b, c}));
		}
		if(ans==INF) cout << 0 << endl;
		else cout << ans << endl;
		
	}
	
	
	
	exit(0);
}
