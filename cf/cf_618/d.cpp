#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second
#define ff first

typedef long long ll;


int main(){ _
	int n; cin >> n;
	if(n%2){ cout << "NO" << endl, exit(0);}
	vector<pair<int, int>> v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.pb({a, b});
	}
	for(int i=0; i<n/2; i++){
		ll dx1 = v[i+1].ff - v[i].ff;
		ll dy1 = v[i+1].ss - v[i].ss;
		ll dx2 = v[(n/2+i)%n].ff - v[(n/2+i+1)%n].ff;
		ll dy2 = v[(n/2+i)%n].ss - v[(n/2+i+1)%n].ss;
//		cout << dx1 << " " << dx2 << " " << dy1 << " " << dy2 << endl;

		if(dx1!=dx2 or dy1 != dy2){
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;

	exit(0);
}
