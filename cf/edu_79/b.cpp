#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	//use ll
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		ll n, s;
		cin >> n >> s;
		vector <ll> v;
		ll soma=0;
		ll maxi=-1;
		ll id=-1;
		bool flag=false;
		for(int i=0; i<n; i++){
			ll a;
			cin >> a;
			if(a>maxi and flag==false){
				id = i;
				maxi = a;
			}
			soma += a;
			if(soma>s){
				if(!flag){
					flag = true;
					soma -= maxi;
				}
			}
			v.pb(a);
		}
		if(!flag)
			cout << 0 << endl;
		else{
			cout << id+1 << endl;
			}
		}
	

	exit(0);
}
