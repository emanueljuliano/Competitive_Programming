#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


int main(){ _
	int q, n, v[100];
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		int a, m=0;
		for(int j=0; j<n; j++){
			cin >> a;
			m+=a;
		}
		int r = m/n;
		if(r*n == m) cout << r << endl;
		else cout << r+1 << endl;
	}
	

	
}
