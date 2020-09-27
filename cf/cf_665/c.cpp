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
		vector<int> v(n);
		int mini = INF;
		for(auto &u: v) {cin >> u; mini=min(mini, u);}
		
		vector<int> cmp(n), w;
		for(int i=0;i <n; i++){
			int u = v[i];
			if(u%mini==0) cmp[i]=1, w.pb(u);
		}

		sort(w.begin(), w.end());
		int at = 0;
		vector<int> ans(n);
		for(int i=0;i <n; i++){
			if(cmp[i]) ans[i]=w[at++];
			else ans[i] = v[i];
		}

		bool show = true;
		for(int i=0;i <n-1; i++) if(ans[i]>ans[i+1]) show = false;
		if(show) cout << "YES" << endl;
		else cout <<"NO" << endl;
	}
	
	
	
	exit(0);
}
