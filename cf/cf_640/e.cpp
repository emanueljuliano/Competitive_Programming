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
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
		}
		if(n==1){cout << 0 << endl; continue;}
		int ans = 0;
		vector<int> soma;
		soma.pb(0);
		for(int i=0;i <n; i++){
			soma.pb(v[i]+soma[i]);
		}
		vector<int> vis(n+10, 0);
		for(int i=0;i <n-1; i++){
			for(int j=i+2;j <=n; j++){
				if(soma[j]-soma[i]>n) break;
				vis[soma[j]-soma[i]] = 1;
			}
		}
		
		for(int i=0;i <n; i++) if(vis[v[i]]) ans++;


		cout << ans << endl;
	}
	
	
	
	exit(0);
}
