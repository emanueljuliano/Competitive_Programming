#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _
	
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int a, b;
		cin >> a >> b;
		if(a==1 and b>1) cout << "NO" << endl;
		else if(a==2 and b > 3) cout << "NO" << endl;
		else if (a==3 and b>3) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}
	exit(0);
}
