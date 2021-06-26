#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		vector<int> maxi(n);
		for (auto &i : v) cin >> i;
		maxi[0] = v[0];
		for (int i=1; i<n; i++) maxi[i] = max(maxi[i-1], v[i]);
		
		int it = n;
		vector<int> ans;
		for (int i=n-1; i>=0; i--) {
			if(v[i] == maxi[i]) {
				for (int j=i; j<it; j++) ans.push_back(v[j]);
				it = i;
			}
		}

		for (auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
