#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int MAX = 1e6+10;
const int MOD = 1e9+7;
const int inf = 0x3f3f3f3f;

int seg[2*MAX];
int fat[2*MAX];
int n;
int maxi = 0;
vector<vector<int>> w(MAX);

ll fexp(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y&1) ret = (ret*x) %MOD;
		y >>=1;
		x = (x*x)%MOD;
	}
	return ret;
}

ll inv(ll x){
	return fexp(x, MOD-2);
}

void fat_build(){
	for(ll i=2; i<2*MAX; i++)
		fat[i] = ((ll)fat[i-1]*i)%MOD; 
}

// cat(n) = (2*n)!/ ((n+1)! * n!)
ll cat(ll x){
	if(x==1) return 1;
	return fat[2*x]%MOD * inv(fat[x+1])%MOD * inv(fat[x])%MOD;
}

int build(){
	for(int i=n-1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
}

int query(int a, int b){
	int ret = inf;
	for(a +=n, b+=n; a<=b; ++a /= 2, --b/=2){
		ret = min(ret, seg[a]);
		ret = min(ret, seg[b]);
	}
	return ret;
}

int main(){ _
	fat[0] = fat[1] = 1;
	fat_build();
	
	cin >> n;
	if(n==0){
		cout << 1 << endl;
		exit(0);
	}
	for(int i=0; i<n; i++){
		cin >> seg[n+i];
		w[seg[n+i]].pb(i);
	}

	build();

	ll ret = 1, at = 1;
	for(int i=0; i<MAX; i++){
		if(w[i].size()<2) continue;
		for(int j=0; j<w[i].size()-1; j++){
		//	cout << "num " << i << " " << j << endl;
		//	cout << "inter " << w[i][j] << " " << w[i][j+1] << endl;
			
			int q = query(w[i][j], w[i][j+1]);
	//		cout << i << " " << w[i][j] << " " << q << endl;
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
