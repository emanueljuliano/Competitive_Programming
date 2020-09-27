#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _
	
	ll n;
	cin >> n;
	vector <ll> v;
	if(n==1){
		cout << 1 << endl;
		exit(0);
	}
	for(ll i=2; i*i<=n; i++){
		if(n%i==0){
			v.push_back(i);
			while(n%i==0)
				n/=i;
		}
	}
	if(n!=1)
		v.push_back(n);

	if(v.size()==1){
		cout << v[0] << endl;
		exit(0);
	}
	else{
		cout << 1 << endl;
		exit(0);
	}


	exit(0);
}
