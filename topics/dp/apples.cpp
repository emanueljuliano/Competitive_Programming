#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int INF = 1e5+10;
int n, k;
vector<int> v;

int pd[1010];
int rec(int x){
	if(x<0) return INF;
	if(x==0) return 0;
	if(pd[x]!=-1) return pd[x];
	int ret = INF;
	for(int i=0; i<v.size(); i++){
		if(v[i]!=-1) ret = min(ret, v[i] + rec(x-i-1));
	//	cout << x  << ret << " " << i << " " << v[i] << endl;
	}
	return pd[x] = ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		memset(pd, -1, sizeof(pd));
		v.resize(0);
		cin >> n >> k;
		for(int i=0; i<k; i++){
			int a; cin >> a;
			v.pb(a);
		}
		int ans = rec(k);
		if(ans<INF)
			cout << ans << endl;
		else cout << -1 << endl;
	}


	exit(0);
}
