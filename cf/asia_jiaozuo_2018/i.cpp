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
		vector<int> v = {0};
		for (int i=0; i<n-1; i++) {
			int a; cin >> a;
			v.push_back(v.back()+a);
		}

		ll at = 0, sum = 0;
		
		int l = 0, r = n;
		vector<ll> ans = {0};
		for (int i=1; i<n; i++) {
			if (i%2==1) {
				r--;
				at += v[r]-v[l];
			}
			else l++;
			sum += at;
			ans.push_back(sum);
		}

		for (int i=0;i <n; i++) {
			cout << ans[i];
			if(i!=n-1) cout << " ";
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
