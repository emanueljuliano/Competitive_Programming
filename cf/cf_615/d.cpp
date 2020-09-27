#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int q, x;
	cin >> q >> x;
	const int MAX = 500010;
	vector<int> v(500010, 0);
	int mex = 0;
	while(q--){
		int a; cin >> a;
		int m = a%x;
			
		ll no =(ll)m + (ll)x*v[m];

		if(v[m]!=0 and  no<(ll)MAX) v[no]++;
		v[m]++;
		if(m==mex%x){
			int aux = mex;
			while(v[aux]!=0) aux++;
			mex = aux;
		}
		cout << mex << endl;
	}


	exit(0);
}
