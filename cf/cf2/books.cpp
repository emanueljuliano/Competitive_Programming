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
	int n, t; cin >> n >> t;

	vector<int> v(n);
	for(auto &i : v) cin >> i;

	vector<int> pref;
	pref.pb(0);
	for(auto u : v) pref.pb(u + pref.back());

	auto val = [&](int x){
		int mini = INF;
		for(int i=x; i<=n; i++){
			mini = min(mini, pref[i]-pref[i-x]);
		}
		return mini <= t;
	};

	int l = 0, r = n;
	while(l<r){
		int m = (l+r+1)/2;
		if(val(m)) l = m;
		else r = m-1;
	}
	cout << l << endl;
	
	
	
	exit(0);
}
