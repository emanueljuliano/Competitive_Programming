#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second

typedef long long ll;


int main(){ _
	int n; cin >> n;
	vector<ll> v;
	for(int i=0; i<n; i++){
		ll a; cin >>a;
		v.pb(a);
	}
	stack<pair<ll, ll>> med;
	pair<ll, ll> aux;
	ll at=0;
	ll sz = 0;
	for(int i=n-1; i>0; i--){
		at+=v[i];
		sz++;
		if(!med.empty()){
		//	cout << i << "HM" << endl;
			aux = med.top();
			while(at*aux.ss>=aux.ff*sz){
				med.pop();
				at += aux.ff;
				sz += aux.ss;

				if(med.empty()) break;
				aux = med.top();
			}
		}if(v[i-1]*sz<at){
			med.push({at, sz});
			at = 0;
			sz = 0;
		}
		
	}
	at += v[0];
	sz++;
	if(!med.empty()){
		aux = med.top();
		while(at*aux.ss>=aux.ff*sz){
			med.pop();
			at += aux.ff;
			sz += aux.ss;
			if(med.empty()) break;
				aux = med.top();
		}
	}
	med.push({at, sz});
		
	cout << setprecision(9) << fixed;
	while(!med.empty()){
		pair<ll, ll> x = med.top(); med.pop();
		for(int i=0; i<x.ss; i++){
			cout << (double)x.ff/x.ss << endl;
		}
	}
	
	exit(0);
}
