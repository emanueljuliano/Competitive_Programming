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
	vector<int> v;
	v.pb(0);
	for(int i=1; i<(int)1e6; i++){
		int at = v[i-1] + (i-1)*3 + 2;
		if(at>(int)1e9) break;
		v.pb(at);
	}
	sort(v.begin(), v.end(), greater<>());
	while(t--){
		int n; cin >> n;
		int ans = 0;
		for(int i=0;i <v.size()-1; i++){
			if(v[i] <= n){
				int mul = n/v[i];
				n-= v[i]*mul;
				ans+=mul;
			}
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
