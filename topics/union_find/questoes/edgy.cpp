#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
const ll MOD = 1e9+7;

ll fexp(ll n, ll k){
	if(k==0) return 1;
	if(k==1) return n;
	if(k%2==0) return fexp((n*n)%MOD, k/2)%MOD;
	return (n*fexp(n, k-1)%MOD) % MOD;
}

int id[100100], sz[100100];

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);
	if(p==q) return;
	if(p>q) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
	return;
}


int main(){ 
	ll n, k;
	int u, v, x;
	cin >> n >> k;
	
	for(int i=0; i<=n; i++){sz[i] = 1; id[i] = i;}
	ll ans = fexp(n, k);
	
	for(int i=0; i<n-1; i++){
		cin >> u >> v >> x;
		if(x==0) uni(u, v);
	}
	
	multiset <int> c;
	for(int i=1; i<=n; i++){
		c.insert(find(i));
	}	
	for(int i=1; i<=n; i++){
		ll val = c.count(i);
		ans = ans - fexp(val, k) + MOD;
		ans %= MOD; 
	}
	cout << ans << endl;
	exit(0);
}
