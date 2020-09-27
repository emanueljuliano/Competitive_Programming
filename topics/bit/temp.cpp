#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e5+10;

struct bit{
	int n;
	vector<ll> bit;

	void build(int n2, vector<int> &v){
		n = n2;
		bit.resize(n2);
		bit[0] = 0;
		
		for(int i=1; i<=n; i++) bit[i] = v[i-1];
		for(int i=1; i<=n; i++){
			int j = i+ (i&-i);
			if(j<=n) bit[j] += bit[i];
		}
	}
	
	int update(int x, int p){
		for(; p<=n; p+= (p&-p)) bit[p] = x;
	}
	
	ll pref(int p){
		ll ret = 0;
		for(; p; p-=p&-p) ret += bit[p];
		return ret;
	}
	
	ll query(int a, int b){
		return pref(b) - pref(a-1);
	}
};

int main(){ _



	exit(0);
}
