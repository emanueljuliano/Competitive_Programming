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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i:v) cin >> i;

		bool show = false;
		for(int i=0; i<n; i++) if(v[i] != v[0]) show = true;

		if(!show) {cout << "NO" << endl; continue;}

		vector<int> vis(n);
		vector<ii> ans;
		vis[0] = 1;
		int dif = 0;
		for(int i=1; i<n; i++){
			if(v[i] != v[0]) ans.pb({0, i}), vis[i]=1, dif=i;
		}
		for(int i=0;i <n; i++){
			if(!vis[i]) ans.pb({i, dif});
		}

		cout << "YES" << endl;
		for(auto [a, b]:ans) cout << a+1 << " " << b+1 << endl;
	}
	
	
	
	exit(0);
}
