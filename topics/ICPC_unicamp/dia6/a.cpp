#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define ff first
#define ss second

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	int maxi = -1;
	vector<pair<int, int>> range;
	vector<int> v;
	for(int i=0; i<n; i++){
		int h, r, t;
		cin >> h >> r >> t;
		maxi = max(maxi, h);
		v.pb(h);
		range.pb({r, t});
	}
	int ans = 0;
	for(int i=0; i<=1825*maxi; i++){
		ans = 0;
		for(int j=0; j<n; j++){
			int mod = v[j];
			if(range[j].ff>range[j].ss){
				if(i%mod<=range[j].ff and i%mod>=range[j].ss)
					ans++;
			}
			else{ 
				if(i%mod<=range[j].ff or i%mod>=range[j].ss)
					ans++;
			}
		}
		if(ans==n){
			cout << i << endl;
			exit(0);
		}
	}
	cout << "impossible" << endl;
	exit(0);
}
