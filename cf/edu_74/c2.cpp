#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
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
		int h, n; cin >> h >> n;
		vector<int> v;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);	
		}
		int ans = 0;
		v.pb(0);
		for(int i=0;i <n-1; i++){
		//	cout << v[i] << " " << ans << endl;
			if(v[i+1]==v[i]-1){
				if(v[i+2]<v[i]-2){
					ans++;
					v[i+1] = v[i+2]+1;
				}
				else i++;
			}
			else if(v[i+1]<v[i]-1){
				v[i] = v[i+1]+1;
				i--;
			}
		}
		
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
