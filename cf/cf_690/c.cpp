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
	vector<string> ans(55);
	for(int i=0; i<(1<<10); i++){
		int sum = 0;
		string val;
		for(int j=1; j<10; j++) if(i&(1<<j)) sum+=j, val+=('0'+j);
		if(!ans[sum].size()) ans[sum] = val;
		else if(ans[sum].size() > val.size()) ans[sum] = val;
		else ans[sum] = min(ans[sum], val);
	}
	int t; cin >> t;
	while(t--){
		int a; cin >> a;
		if(!ans[a].size()) cout << -1 << endl;
		else cout << ans[a] << endl;
	}
	
	
	
	exit(0);
}
