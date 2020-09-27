#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e6+10;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;

ll fat[2*MAX];
int v[MAX];
int n;

ll fexp(ll a, int b){
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2) return (a*fexp((a*a)%MOD, b/2)%MOD)%MOD;
	return fexp((a*a)%MOD, b/2)%MOD;
}

ll inv(ll x){
	return fexp(x, MOD-2);
}

void fat_build(){
	for(ll i=2; i<2*MAX; i++)
		fat[i] = (fat[i-1]*i)%MOD; 
}

// cat(n) = (2*n)!/ ((n+1)! * n!)
ll cat(ll x){
	if(x==1) return 1;
	return fat[2*x]%MOD * inv(fat[x+1])%MOD * inv(fat[x])%MOD;
}

ll seg[4*MAX];
ll build(int p=1, int l=0, int r=n-1){
	if(l==r) return seg[p] = v[l];
	int m = (l+r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

ll query(int a, int b, int p=1, int l=0, int r=n-1){
	if (b<l or r<a) return inf;
	if (a<=l and r<=b) return seg[p];
	int m = (l+r)/2;
	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main(){ _
	fat[0] = fat[1] = 1;
	fat_build();
	
	cin >> n;
	if(n==0){
		cout << 1 << endl;
		exit(0);
	}

	vector<vector<int>> w(MAX);
	for(int i=0; i<n; i++){
		cin >> v[i];
		w[v[i]].pb(i);
	}
	
	build();

	ll ret = 1, at = 1;
	for(int i=0; i<MAX; i++){
		if(w[i].size()<2) continue;
		for(int j=0; j<w[i].size()-1; j++){
		//	cout << "num " << i << " " << j << endl;
		//	cout << "inter " << w[i][j] << " " << w[i][j+1] << endl;
			
			int q = query(w[i][j], w[i][j+1]);
			if(q<i){
				ret = (ret*cat(at))%MOD;
				at = 1;
			}
			else{
				at++;
			}
		}
		ret = (ret*cat(at))%MOD;
		at = 1;
	}
	
	cout << ret << endl;

	exit(0);
}

