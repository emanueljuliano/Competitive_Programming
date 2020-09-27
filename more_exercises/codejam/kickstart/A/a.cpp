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
	int aux = t;
	while(t--){
		int n, b; cin >> n >> b;
		vector<int > v;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i=0; i<n; i++){
			if(v[i]<=b) b-=v[i], ans++;
			else break;
		}

		cout << "Case #" << aux-t << ": " << ans << endl;

	}
	
	
	
	exit(0);
}
