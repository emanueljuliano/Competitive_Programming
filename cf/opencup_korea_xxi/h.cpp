#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 2e5;

int main(){ _
	int n; cin >> n;
	vector<ll> v(MAX, 0);
	
	ll sum = 0;
	for(int i=0;i <n; i++) cin >> v[i], sum += v[i];
	if(sum==1){
		if(v[0]==1) cout << 1 << endl;
		for(int i=1; i<n; i++) if(v[i]) cout << i << endl;
		exit(0);
	}

	int l = 1, r = MAX-2;
	while(l<r){
		int m = (l+r+1)/2;
		vector<ll> w = v;
		for(int i=m; i<n; i++) w[0]+=v[i];

		ll at = 1;
		for(int i=m-1; i>=1; i--){
			if(v[i]<at) at += at-v[i];
			else w[0] += v[i]-at;
			if(at>sum) break; 
		}
		if(w[0]>=at) l = m;
		else r = m-1;
	}
	
	cout << l << endl;

	
	exit(0);
}
