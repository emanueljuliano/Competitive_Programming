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
			int a; cin >> a; v.pb(a);
		}
		bool flag = true;
		for(int i=0;i <n; i++){
			if(v[i]==1){
				for(int j=1; j<n; j++){
					if(v[(i+j)%n] < v[(i+j+1)%n]) flag = false;
				}
				if(flag) break;
				flag = true;
				for(int j=0; j<n-1; j++){
					if(v[(i+j)%n] > v[(i+j+1)%n]) flag = false;
				}
				break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
