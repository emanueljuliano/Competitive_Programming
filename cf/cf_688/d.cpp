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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll k; cin >> k;
		if(k%2){cout << -1 << endl; continue;}

		vector<int> ans;
		int tot = 0;
		for(int i=60; i>=1; i--){
			if(k & 1LL<<i) ans.pb(i-1), ans.pb(1), tot+=i-1, tot++;			
		}
		cout << tot << endl;
		for(int i=0;i <ans.size(); i++){
			if(ans[i]) cout << 1 << " ";
			for(int j=0; j<ans[i]-1; j++) cout << 0 << " ";
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
