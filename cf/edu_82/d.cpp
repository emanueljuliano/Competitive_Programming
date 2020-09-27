#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ //_
	int t; cin >> t;
	vector<ll> v;
	while(t--){
		vector<int> w(100);
		v.resize(0);
		ll n, m; cin >> n >>m;
		if(n<m) {cout << -1 << endl; continue;}
		int maxi = 10;
		ll soma = 0;	
		for(int i=0; i<m; i++){
			ll a; cin >> a;
			v.pb(a);
			ll aux = a;
			soma+=a;
			int num = 0;
			while(a/2>0){
				a/=2;
				num++;
			}
			w[num]++;
			maxi = max(maxi, num);
		}
		
		ll a = n;
		vector<int> bi(100, 0);
		for(int i=0; a>0; i++){
			if(a%(ll)2){ bi[i]=1; soma-=1<<i;}
			a = a/(ll)2;
		}
		
		int ans = 0;
		ll at = 0;
		for(int i=maxi; i>0; i--){
			if(bi[i]==1){
				at += 1<<i;
				soma += 1<<i;
			}
			cout << i << " a " << at << endl;
			if(w[i]>0){
				ll n_at=1<<i;
				for(int j=0; j<w[i]; j++){
					if(soma-n_at>at){soma -=n_at/2; w[i-1]++; ans++;}
					
					else{at-=n_at; soma-=n_at;}
				}	 
			}
			cout << i << " b " << at <<  " ans " << ans << endl;
		}
		if(at+bi[0]!=w[0]){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
		}
		

	}


	exit(0);
}
