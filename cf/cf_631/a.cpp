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
		int n, x; cin >> n >> x;
		int aux = n+x+100;
		vector<int> v(n+x+200, 0);
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v[a] = 1;
		}
		for(int i=1; i<=aux; i++){
			if(x==0) break;
			if(v[i]!=1) x--;
			v[i] = 1;
		}
		int ans = 1;
		for(int i=1; i<=aux; i++){
			if(v[i]==0) break;
			ans = i;
		}
		cout << ans << endl;

	}
	
	
	
	exit(0);
}
