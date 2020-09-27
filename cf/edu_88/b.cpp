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
		int n, m, x, y; cin >> n >> m >> x >> y;
		ll ans = 0;
		bool val = 2*x<=y;
		for(int i=0;i <n; i++){
			string s; cin >> s;
			for(int j=0; j<m; j++){
				if(s[j]=='.'){
					if(val) ans += x;
					else{
						int at = 0;
						while(j<m and s[j]=='.') j++, at++;
						ans += y*(at/2);
						ans += (at%2)*x;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
