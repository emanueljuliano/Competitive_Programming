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
		int n, k; cin >> n >> k;
		vector<int> s(n);
		vector<ii> v;
		for(int i=0;i <n; i++) for(int j=0; j<3; j++){
			int a; cin >> a; v.pb({a, i});
		}
		sort(v.begin(), v.end());
		int at = 0;
		int ans = 0;
		for(auto p : v){	
			if(at>=k) break;
			if(s[p.s]==2) continue;
			ans += p.f;
			s[p.s]++;
			at++;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
