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
	int n; cin >> n;

	vector<int> a(n);
	int tot = 0, maxi = 0;
	for(auto &i : a) cin >> i, tot+=i, maxi = max(maxi, i);
	
	int sq = sqrt(tot) + 1;
	vector<int> pref;
	pref.pb(0);
	for(auto &i :a) pref.pb(pref.back() + i);
	
	vector<int> memo(sq+1);
	int q; cin >> q;

	while(q--){
		int t; cin >> t;
		if(t<maxi){cout << "Impossible" << endl; continue;}

		if(t<sq){ // small
			if(memo[t]!=0) {cout << memo[t] << endl; continue;}
			int sum = 0, at =0;
			for(auto &i : a){
				if(sum+i<=t) sum+=i;
				else at++, sum=i;
			}
			at++;
			memo[t] = at;
			cout << at << endl;
		}
		else{ // big
			int sum = 0, at =0;
			while(true){
				at++;
				int up = upper_bound(pref.begin(), pref.end(), sum+t) - pref.begin();
				if(up==pref.size()) break;
				up--;
				sum = pref[up];
			}
			cout << at << endl;
		}
	}
	
	
	
	
	exit(0);
}
