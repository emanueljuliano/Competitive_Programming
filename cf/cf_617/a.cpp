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
		int imp = 0, par = 0;
		for(int i=0; i<n; i++){
		
			int a; cin>>a;
			if(a%2) imp++;
			else par++;
		}
		if(par==n){
			cout << "NO" << endl;
		}
		else if(imp==n){
			if(n%2){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		else{
			cout << "YES" << endl;
		}
	}

	


	exit(0);
}
