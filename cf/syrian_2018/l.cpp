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
	//freopen("file.in", "r", stdin);	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		int maxi = 0;
		vector<int> vis(n, -1);
		for(int i=0;i <n; i++){
			cin >> v[i];
			maxi = max(maxi, v[i]);
			if(v[i]!=0 and vis[v[i]]==-1) vis[v[i]] = i;
		}
		int at = 0;
		bool show = true;
		for(int i=n-1;i+1; i--){
			if(v[i]!=0){
				at = min(at+1, maxi);
				v[i] = at;
			}
			else{
				
			}
		}
	}
	
	
	exit(0);
}
