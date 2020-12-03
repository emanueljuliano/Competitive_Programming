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
		ll n, x, y; cin >> n >> x >> y;
		vector<int> v;
		int d = y-x;
		for(int j=1; j<=d; j++) if(d%j==0 and d/j<n){
			if(y>n*j) for(int i=y; v.size()<n; i-=j) v.pb(i);
			else{
				if(x%j) for(int i=x%j; v.size()<n; i+=j) v.pb(i);
				else for(int i=j; v.size()<n; i+=j) v.pb(i); 
			}
			break;
		}
		sort(v.begin(), v.end());
		for(auto u : v) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
