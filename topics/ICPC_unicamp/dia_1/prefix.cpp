#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef unsigned long long ll;
typedef vector<vector<ll > > vvl;
typedef vector<vector<ll > > matrix;


bool flag = false;
vvl Ma(32, vector<ll>(32, 0));
vector<ll> v;
ll n, k;

vvl mult(vvl M1, vvl M2){
	vvl M3(32, vector<ll> (32, 0));
	for(int i=0; i<32; i++){
		for(int j=0; j<32; j++){
			ll soma = 0;
			for(int ii = 0; ii<32; ii++){
				if (M1[i][ii] and k/M1[i][ii] < M2[ii][j]) flag = true;
				M3[i][j] += M1[i][ii]*M2[ii][j];
				if(M3[i][j]>=k) flag = true;
			}
		}
	}
	return M3;
}

vvl identity(ll k){
  matrix v1(k, vector<ll>(k, 0));
  for (int i = 0; i < k; i++)
    v1[i][i] = 1;
  return v1;
}

vvl fexp(vvl M, ll k){
  if (k == 0) return identity(M.size());
	if(k==1) return M;
	if(k%2==0) return fexp(mult(M, M), k/2);
	else return mult(M, fexp(mult(M, M), (k-1)/2));
}

bool check(ll x){
	flag = false;
	vvl ans = fexp(Ma, x);
	ll soma = 0;
	//cout << x << " ";
	for(int i=0; i<n; i++){
		if (ans[i][j] and k/ans[i][j] < v[j]) flag = true;
		soma += ans[i][j]*v[j];
//		cout << soma << " ";
		if(soma>=k) flag = true;
	}
//	cout << k <<endl;
	return flag;
}

ll bb(ll l, ll r){
	if(l==r) return l;
	ll m = (l+r)/2;
	if(check(m))
		return bb(l, m);
	else
		return bb(m+1, r);
}

int main(){ ios_base::sync_with_stdio(0);cin.tie(0);

	cin >> n >> k;
	ll ans=0;
	for(int i=0; i<n; i++){
		ll a; cin >>a;
		if(a!=0 or v.size())
			v.pb(a);
		ans= max(ans, a);
	}
	n = v.size();	
	ll c = 1;
	if(ans>=k){
		cout << 0 << endl;
		return 0;
	}
	if(n>30){
		vector <ll> aux;
		ll i = 1;
		ll sum = v[0];
		while(v[i]+sum<k){
			ll ax = v[i];
			v[i] += sum;
			sum += ax;
			i = (i+1)%n;
			if(!i){
				v.pb(sum);
				sum = 0;
				c++;
				n++;
			}
		}
		cout << c << endl;
	}

	else{
		for(int i=0; i<n; i++)
			for(int j=0; j<=i; j++)
				Ma[i][j] = 1;
		ll c = bb(0, 1+1e18+1);
		cout << c+1 << endl;
	}

	return 0;
}
