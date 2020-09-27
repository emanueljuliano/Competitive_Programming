#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;




int main(){ _
	int t, n, m;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		ll p1=0, p2=0, i1=0, i2=0, p, q;
		for(int j=0; j<n; j++){
			cin >> p;
			if(p%2==0) p1++;
			else i1++; 
		}
		cin >> m;
		for(int j=0; j<m; j++){
			cin >> q;
			if(q%2==0)p2++;
			else i2++;
		}
		cout << i1*i2 + p1*p2 << endl;		
	}




	exit(0);
}
