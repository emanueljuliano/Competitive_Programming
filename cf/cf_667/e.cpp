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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i: v) cin >> i;
		int aux; for(int i=0;i <n; i++) cin >> aux;
		sort(v.begin(), v.end());

		vector<int> get(n);
		for(int i=0;i <n; i++){
			get[i] = upper_bound(v.begin(), v.end(), v[i]+k) - v.begin();
			get[i] -= i;
		}

		vector<int> maxi(n);
		maxi[n-1] = get[n-1];
		for(int i=n-2; i+1; i--) maxi[i] = max(maxi[i+1], get[i]);
		int ans = 0;
		for(int i=0;i <n; i++){
			int at = get[i];
			int up = upper_bound(v.begin(), v.end(), v[i]+k) - v.begin();
			if(up<get.size()) at += maxi[up];
			ans = max(ans, at);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
