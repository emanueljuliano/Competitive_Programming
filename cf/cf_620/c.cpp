#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef long long ll;


int main(){ _
	int tc;cin >> tc;
	while(tc--){
		int n, m;
		cin >> n>> m;
		vector<pair<int, pair<int, int>>> v;
		for(int i=0; i<n; i++){
			int t, l, h; cin >> t >> l >> h;
			v.pb({t, {l, h}});
		}	
		sort(v.begin(), v.end());
		int at = m;
		int mini = m;
		int maxi = m;
		int t0 = 0;
		bool ans = true;
		for(int i=0; i<n; i++){
			int t = v[i].f;
			int l = v[i].s.f;
			int h = v[i].s.s;
			int mini2 = mini;

			if(l<mini){
				if(abs(l-mini) <= t-t0) mini = l;
				else mini -= t-t0;
			}
			else if(l>maxi){
				if(abs(l-maxi) <= t-t0) mini = l;
				else ans = false;
			}
			else mini = l;

			if(h>maxi){
				if(abs(h-maxi) <= t-t0) maxi = h;
				else maxi += t-t0;
			}
			else if(h<mini2){
				if(abs(h-mini2) <= t-t0) maxi = h;
				else ans = false;
			}
			else maxi = h;
		
			t0 = t;
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	exit(0);
}
