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
	int n, m, q; cin >> n >>m >> q;
	string s, t; cin >> s >> t;

	vector<int> pref;
	pref.pb(0);
	for(int i=0;i <n; i++){
		int ap = true;
		if(i+m-1<n){for(int j=0; j<m and i+j<n; j++){
			if(s[i+j]!=t[j]) ap = false;
		}}
		else ap = false;
		pref.pb(pref[i]+ap);
	}
	while(q--){
		int l, r; cin >> l >> r;
		if(r-m+1<l) cout << 0 << endl;
		else cout << pref[r-m+1]-pref[l-1] << endl;
	}
	
	
	
	exit(0);
}
