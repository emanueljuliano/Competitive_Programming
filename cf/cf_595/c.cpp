#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef unsigned long long ll;

const int max3 = 38;
ll p3[100];
ll soma[100];
ll teste[1000000];
void build(){
	p3[0] = 1;
	soma[0] = 1;
	for(int i=1; i<=max3; i++){
		p3[i] = 3*p3[i-1]; 
		soma[i] = p3[i] + soma[i-1];
	}
}


int main(){	_
	memset(teste, -1, sizeof(teste));
	int q;
	ll n;
	cin >> q;
	build();
	for(int i=0; i<q; i++){
		cin >> n;
		ll resp = 0;
		ll m = n;
		ll flag = 100;
		
		for(int j=max3; j>=0; j--){
			if (m<p3[j]){ flag=j; continue;}
			if(m>=p3[j]){ m-=p3[j]; resp+=p3[j];}
		}
		if(m==0) cout << n << endl;
		else{
			if(p3[flag]>resp) cout << p3[flag] << endl;
			else{
				for(int j=0; p3[j]<p3[flag]; j++){
					resp-=p3[j];
				}
				cout << resp + p3[flag] << endl;
				
			}
		}
	}


	exit(0);
}
