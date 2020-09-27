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
			int a; cin >> a;
			v.pb(a);
		}
		vector<int> w;
		w.pb(v[0]);
		for(int i=1;i <n; i++){
			w.pb(max(w[i-1], v[i]));
		}
		int ans = 0;
		for(int i=0;i <n;i ++){
			if(v[i]<w[i]){
				int a = w[i] - v[i];
				int x = 0;
				for(int j=0;j <=30; j++){
					if(a>=(1<<j)) ans = max(ans, j+1);
					else break;
				}
			}
		}
		cout << ans << endl;	
	}
	
	
	
	exit(0);
}
