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

ll msb(ll x){
	return __builtin_clzll(1ll) - __builtin_clzll(x);
}

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i : v) cin >> i;
	
	if(n>200){
		cout << 1 << endl;
		return 0;
	}
	else{
		vector<int> pref(n+1);
		pref[0] = 0;
		for(int i=0; i<n; i++) pref[i+1] = pref[i]^v[i];
		int ans = INF;
		for(int i=0;i <n; i++){
			for(int j=i; j<n; j++) for(int k=j+1; k<n; k++){
				// i-j, j-k
				if((pref[j+1]^pref[i]) > (pref[k+1]^pref[j+1])) ans = min(ans, k-j-1+j-i);
			}
		}
		if(ans==INF) cout << -1 << endl;
		else cout << ans << endl;
		return 0;
	}

	int ans = INF;
	for(int i=n-1; i>0; i--){
		ll at = v[i];
		int it = i-1;
		while(it>0 and v[it]<=at and msb(v[it]) == msb(at)) at^=v[it], it--;
		if(v[it]>at) ans = min(ans, i-it-1);
	}
	for(int i=0; i<n-1; i++){
		ll at = v[i];
		int it = i+1;
		while(it<n-1 and v[it]>=at and msb(v[it]) != msb(at)) at^=v[it], it++;
		if(v[it]<at) ans = min(ans, it-i-1);
	}
	if(ans==INF) cout << -1 << endl;
	else cout << ans << endl;

	
	
	
	exit(0);
}
