#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		ll n;
		cin >> n;
		if(n>=15 and n%14 >0 and n%14<=6) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	exit(0);
}
