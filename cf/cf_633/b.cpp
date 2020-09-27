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
		vector<int> v;
		int n;cin >> n;
		vector<int> ans;
		for(int i=0;i<n; i++){
			int a; cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		
		int it = 0;
		for(int i=0;i <n/2; i++){
			ans.pb(v[i]);
			ans.pb(v[n-1-i]);
		}
		if(n%2) ans.pb(v[n/2]);
		reverse(ans.begin(), ans.end());
		for(int i=0;i <n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
