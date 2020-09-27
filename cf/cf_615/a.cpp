#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int a, b, c; cin >> a >> b >> c;
	
		vector<int> v = {a, b, c};
		sort(v.begin(), v.end());
		int x; cin >> x;
		int at = v[2] - v[0] + v[2]-v[1];
		if(at>x) {cout << "NO" << endl; continue;}
		x -= at;
		if(x%3!=0){cout <<"NO" << endl; continue;}
		cout << "YES" << endl;
	}


	exit(0);
}
