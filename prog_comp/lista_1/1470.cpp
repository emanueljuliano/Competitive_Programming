#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

int n, m;
vector<int> w;

bool rec(vector<int> v){
	if(v.size()<m) return false;
	if(v==w) return true;
	reverse(v.begin(), v.end());
	if(v==w) return true;

	vector<int> aux1;
	vector<int> aux2;
	vector<int> test;
	bool flag = false;
	for(int i=1; i<v.size();i++){
		aux1.resize(0), aux2.resize(0), test.resize(0);
		
		int x = 0;
		for(int j=i-1; j>=0; j--) aux1.pb(v[j]);
		for(int j=i; j<v.size(); j++) aux2.pb(v[j]);
		for(int j=0; j<min(aux1.size(), aux2.size()); j++) test.pb(aux1[j]+aux2[j]), x++;
		
			
		if(aux1.size()>aux2.size()) for(int j=x; j<aux1.size(); j++) test.pb(aux1[j]);
		else if(aux1.size()<aux2.size()) for(int j=x; j<aux2.size(); j++) test.pb(aux2[j]);

		if(rec(test)) flag = true;
	}
	return flag;
}

int main(){ _
	while(cin>>n){
		w.resize(0);
		vector<int> v;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
		}
		cin >> m;
		for(int i=0; i<m; i++){
			int a; cin >> a;
			w.pb(a);
		}
		bool ans = rec(v);
		if(ans) cout <<"S" << endl;
		else cout << "N" << endl;
	}


	exit(0);
}
