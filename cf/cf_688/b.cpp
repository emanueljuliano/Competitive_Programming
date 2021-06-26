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
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;

		int best;
		best = abs(v[0]-v[1]);
		best = max(best, abs(v[n-1]-v[n-2]));
		for(int i=1; i<n-1; i++){
			if(v[i-1]<v[i] and v[i+1]<v[i]) best = max(best, 2*min(v[i]-v[i-1], v[i]-v[i+1]));
			if(v[i-1]>v[i] and v[i+1]>v[i]) best = max(best, 2*min(v[i-1]-v[i], v[i+1]-v[i]));
		}

		ll tot = 0;
		for(int i=1; i<n; i++){
			tot += abs(v[i] -v[i-1]);
		}
		
		cout << tot-best << endl;

	}
	
	
	
	exit(0);
}
