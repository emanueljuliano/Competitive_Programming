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
		int n, m; cin >> n >> m;
		vector<ii> ent;
		for(int i=0;i <m; i++){
			int r, c; cin >> r >> c;
			ent.pb({c, r});
		}
		sort(ent.begin(), ent.end());
		
		int at = -1, pt=-1;
		vector<int> v(m+1), X(m+1);
		for(auto [c, r] : ent){
			if(c!=at) at = c, pt++;
			v[pt]+=r;
			X[pt] = c;
		}
		v[++pt]=3, X[pt++] = n+1;
		bool ans = true;
		int a = 0, b = 0, eq=1;
		for(int i=0;i <pt; i++){
			int x = X[i];
			if(v[i]==3){
				if(!eq) ans = false;
				a = x, b=x;
			}
			else if(v[i]==1){
				if(eq) {
					a = x, b = x+1;
				}
				else {
					if((x-1-a)%2) ans = false;
					a = x+1, b = x+1;
				}
				eq^=1;
			}
			else if(v[i]==2){
				if(eq) {
					a = x+1, b = x;
				}
				else {
					if((x-1-b)%2) ans = false;
					a = x+1, b = x+1;
				}
				eq^=1;
			}
		}
	
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
