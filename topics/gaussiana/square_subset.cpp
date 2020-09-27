#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int LOG = 25;
const int MOD = 1e9+7;

vector<int> basis(LOG, 0);
int rk=0;

void insert(int mask){
	for(int i=LOG-1; i>=0; i--) if(mask>>i&1){
		if(!basis[i]){
			basis[i] = mask; rk++;
			return;
		}
		mask^= basis[i];
	}
}

int primo[80];
map<int, int> mp;
int ptr = 0;
void crivo(){
	for(int i=0;i <80; i++) primo[i] = 1;
	primo[1] = 0;
	for(int i=2; i<80; i++) if(primo[i]){
		mp[i] = ptr++;
		for(int j=2*i; j<80; j+=i) primo[j]=0;
	}
}

int main(){ _
	int n; cin >> n;
	
	crivo();
	ll ans = 1;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		
		vector<int> fact;
		for(int j=2; j*j<=a; j++) if(a%j==0){
			int at = 0;
			while(a%j==0) at++, a/=j;
			if(at%2) fact.pb(j);
		}
		if(a!=1) fact.pb(a);

		int msk = 0;
		for(auto u : fact) msk|= 1<<mp[u];
		if(msk) insert(msk);
	}

	for(int i=0;i <n-rk; i++) ans = (ans*2)%MOD;
	
	cout << ((ans-1)+MOD)%MOD << endl;

	exit(0);
}
