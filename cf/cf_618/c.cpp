#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second

typedef long long ll;

map<int, vector<int> > ma;

int main(){ _
	
	int na; cin >> na;
	vector<int> v;
	vector<int> aux;
	for(int i=0; i<na; i++){
		int a; cin >> a;
		v.pb(a);

		aux.resize(0);
		int at = a;
		for(int j=0; at>0; j++){    
			aux.pb(at%2);    
			at= at/2;
		}
		for(int j=0; j<aux.size(); j++){
			if(aux[j]) ma[-j].pb(a);
		}
	} 

	int ans = 0;
	for(auto x : ma){
		if(x.ss.size()==1){
			ans = x.ss[0];
			break;
		}
	}
	if(ans!=0){
		cout << ans << " ";
		for(int i=0; i<v.size(); i++){
			if(v[i]!=ans) cout << v[i] << " ";
		}
		cout << endl;
	}
	else{
		for(int i=0; i<v.size(); i++){
			cout << v[i] << " " ;
		}
		cout << endl;
	}
	
	exit(0);
}
