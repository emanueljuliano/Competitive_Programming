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
		string s; cin >> s;
		int ans = 0;
		int it = 0;
		vector<int> vis(n);
		for(int i=0; i<n; i++){
			while(i<=n and vis[i]) i++;
			if(i>n) break;

			it = max(i, it);
			while(it<n-1 and s[it]!=s[it+1]) it++;
			if(it>=n-1){
				n--;
				while(vis[n]) n--;
				it = n;
			}
			vis[it] = 1;
			while(i<n-1 and s[i]==s[i+1]) i++;
		//	cout << i << " " << it << endl;
			

			ans++;
			it++;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
