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
		int n, k, m; cin >> n >> k >> m;
		vector<int> vis(n);
		for(int i=0;i <m; i++){
			int a; cin >> a; a--; vis[a]=1;
		}
		vector<int> pos;
		for(int i=0;i <n; i++) if(!vis[i]) pos.pb(i);

		if(pos.size() %(k-1)){
			cout << "NO" << endl; continue;
		}

		bool show = false;
		for(int i=k/2-1;i <pos.size()-(k/2); i++){
			if(pos[i+1]!=pos[i]+1) show = true;
		}

		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	
	
	
	exit(0);
}
