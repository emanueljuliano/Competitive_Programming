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
		vector<int> v(n), w(n);
		for(auto &i: v) cin >> i;
		for(auto &i: w) cin >> i;
		vector<int> vp, vn;
		int at = 0;
		int tot = 0;
		for(int i=0;i <n; i++){
			if(w[i]==0 and v[i]>0) vp.pb(v[i]);
			else if(w[i]==0 and v[i]<=0) vn.pb(v[i]);
			else at += v[i];
			tot += v[i];
		}
		if(tot<0){
			for(auto u : v) cout << u << " ";
			cout << endl;
			continue;
		}

		sort(vp.begin(), vp.end(), greater<>());
		sort(vn.begin(), vn.end(), greater<>());
		vector<int> ans(n);
		int suf = 0;
		for(int i=n-1; i+1; i--){
			if(w[i]==1) ans[i] = v[i], tot-=v[i], suf+=v[i];
			else{
				int u;
				if(vn.size()) u=vn.back(), vn.pop_back();
				else u = vp.back(), vp.pop_back();
				ans[i] = u, tot-=u;
			}
		}
		for(auto u : ans) cout << u << " ";
		cout << endl;
	}

	exit(0);
}
