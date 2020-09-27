#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


int main(){ _
	
	int q, n;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		if(n==2) cout << 2 << endl;
		else if(n%2==1) cout << 1 << endl;
		else if(n%2==0) cout << 0 << endl;
	}

}
