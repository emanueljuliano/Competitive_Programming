#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=2; i*i<=n; i++){
			if(n%i==0) {n/=i;v.pb(i);}
			if(v.size()==2) {v.pb(n);n=1; break;}
		}
		if(n>1) v.pb(n);
		if(v.size()<3){cout << "NO" << endl; continue;}
		if(v[2]==v[1]){cout << "NO" << endl; continue;}
		cout << "YES" << endl;
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
	}
	exit(0);
}
