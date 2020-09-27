#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;



int main(){	_
	int q;
	int n;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		int v[220];
		int resp = n;
		for(int j=1; j<=n; j++){
			cin >> v[j];
		}
		int w[220];
		for(int j=1; j<=n; j++){
			int c = 1;
			int at = j;	
			while(v[at]!=j){
				at = v[at];
				c+=1;
			}
			w[j] = c;
		}
		for(int j=1; j<=n; j++){
			cout << w[j] << " ";
		}
		cout << endl;

	 }
	


	exit(0);
}
