#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m;
	cin >> n >> m;
	vector <string> v, w;
	for(int i=0; i<n; i++){
		string a; cin >> a;
		v.pb(a);
	}
	for(int i=0; i<m; i++){
		string a; cin >> a;
		w.pb(a);
	}
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;
		x--;
		cout << v[x%n] << w[x%m] << endl;
	}



	exit(0);
}
