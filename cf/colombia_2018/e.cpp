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
int n;
int esc(int x, int y){
	int ret = 0;
	for(int i=0;i <=n; i++){
		for(int j=0; j<=n; j++){
			if(i+j>n) continue;
			int dx = abs(x-i);
			int dy = abs(y-j);
			if(__gcd(dx, dy)>1){
					ret++;
			//	if(x==0 and y==0) cout << i << " " << j << endl;
			}
		//	if(dx==0 and dy>1) ret++;
		//	if(dy==0 and dx>1) ret++;
		}
	}
	return ret;

}

int main(){ _

	cin >> n;
	int ans = 0;
	for(int i=0;i <=n; i++){
		for(int j=0; j<=n; j++){
			if(i+j>n) continue;
			ans += esc(i, j);
			//cout << i << " " << j << " " << ans << endl;
		}
	}
	cout << ans/2 << endl;
	
	
	exit(0);
}
