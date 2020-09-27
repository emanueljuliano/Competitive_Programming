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
		if(n==2) cout << 1 << endl;
		if(n==3) cout << 7 << endl;
		if(n>=4){
			if(n%2!=1){
				for(int i=0; i<n/2; i++){
					cout << 1;
				}
				cout << endl;
			}
			else{
				cout << 7;
				for(int i=0; i<n/2-1; i++){
					cout << 1;
				}
				cout << endl;
			}			
		}
	}


	exit(0);
}
