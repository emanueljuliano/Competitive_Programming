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
		int n, s; cin >> n >> s;
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
		int ans = 0;
		for(int i=0;i <(1<<n); i++){
			int soma = 0;
			int mini = INF;
			for(int j=0; j<n; j++) if((1<<j) & i){
				soma += v[j];
				mini = min(mini, v[j]);
			}
		//	cout << i << " " << mini << " " << soma << " " << endl;
			if(soma>=s and soma-mini<s) ans = max(ans, __builtin_popcount(i));
		}	
		cout << ans << endl;
	}	
	
	exit(0);
}
