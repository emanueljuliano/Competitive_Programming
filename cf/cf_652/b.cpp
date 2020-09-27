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
		string s; cin >> s;
		string ans;
		int it = n-1;
		while(it>=0 and s[it]=='1'){
			it--;
		}
		if(it==-1){
			cout << s << endl;
			continue;
		}
		
		for(int i=0;i <it; i++){
			if(s[i]=='0') ans.pb(s[i]);
			else break;
		}
		for(int i=it; i<n; i++) ans.pb(s[i]);
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
