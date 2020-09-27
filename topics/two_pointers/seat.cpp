#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m, k; cin >> n >> m >> k;
	vector<string> v(n);
	for(auto &i: v) cin >> i;
	
	int ans = 0;
	if(k<=n)for(int i=0;i <n; i++){
		int at = 0;
		for(int j=0; j<k; j++) if(v[i][j]=='*') at++;
		if(!at) ans++;
		for(int j=1; j<m-k; j++){
			at -= (v[i][j] =='*');
			at +=  (v[i][j+k] =='*');
			if(!at) ans++;
		}
	}
	if(k<=m)for(int i=0;i <m; i++){
		int at = 0;
		for(int j=0; j<k; j++) if(v[i][j]=='*') at++;
		if(!at) ans++;
		for(int j=1; j<m-k; j++){
			at -= (v[i][j] =='*');
			at +=  (v[i][j+k] =='*');
			if(!at) ans++;
		}
	}
	

	exit(0);
}
