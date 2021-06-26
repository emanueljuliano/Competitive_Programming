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
		vector<int> c(3), a(5);
		for(auto &i : c) cin >> i;
		for(auto &i : a) cin >> i;
		
		c[0] -= a[0];
		c[1] -= a[1];
		if(c[0]>0) {
			if(c[0]>=a[3]) {
				c[0]-=a[3];
				a[3]=0;
			}
			else{
				int res = c[0];
				a[3]-=res;
				c[0] = 0;
			} 
		}
		if(c[1]>0){
			if(c[1]>=a[4]) {
				c[1]-=a[4];
				a[4]=0;
			}
			else{
				int res = c[1];
				a[4]-=res;
				c[1] = 0;
			} 
		}
		c[2]-=a[2]+a[3]+a[4];
		bool show = true;
		for(int i=0; i<3; i++) show &=(c[i]>=0);
		if(show) cout << "YES" << endl;
		else cout << "NO" <<endl;
	}
	
	
	
	exit(0);
}
