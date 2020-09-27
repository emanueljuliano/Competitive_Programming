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
		vector<int> v(n);
		for(auto &i: v) cin >> i;
		sort(v.begin(), v.end());
		bool show = true;
		for(int i=1; i<n; i++) if(v[i]> v[i-1]+1) show = false;
		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}
	
	
	
	exit(0);
}
