#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<2*n; i++){
			int a; cin >>a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		int ans = v[n] - v[n-1];
		cout << ans << endl;
	}


	exit(0);
}
