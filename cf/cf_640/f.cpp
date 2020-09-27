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
		int a, b, c; cin >> a >> b >> c;
		vector<int> ans;
		int x = 1;
		if(a)for(int i=0;i <a+1; i++){
			ans.pb(0);
		}
		if(c){
			for(int i=0; i<c+1; i++) ans.pb(1);
		}
		if(a>0 and c>0) x = 1;
		else if(a>0 or c>0) x = 0;
		else x= -1;
		if(b)for(int i=0; i<b-x; i++){
				if(ans.empty()) ans.pb(0);
				else if(ans.back()==0) ans.pb(1);
				else ans.pb(0);
		}
	
		for(auto k : ans) cout << k;
		cout << endl;
	
	}
	
	
	
	exit(0);
}
