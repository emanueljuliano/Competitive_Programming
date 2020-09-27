#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int inf = 0x3f3f3f3f;
int n, k;
int pd[1010][1010];
vector<int> v;

int rec(int pos, int g){
	if(g==0) return inf;
	if(pos==n) return 0;
	if(pd[pos][g]!=-1) return pd[pos][g];
	return pd[pos][g] = min(v[pos]-v[pos-1] + rec(pos+1, g), rec(pos+1, g-1));
}

int main(){ _
	while(cin >> n >> k){
		memset(pd, -1, sizeof(pd));
		v.resize(0);
		v.pb(0);
		for(int i=0; i<n-1; i++){
			int a; cin >> a;
			v.pb(a);
		}
		int ans = rec(1, k);
		
		cout << ans << endl;
	}


	exit(0);
}
