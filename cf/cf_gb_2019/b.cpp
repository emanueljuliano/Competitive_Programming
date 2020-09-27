#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> v;
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			v.pb(a);
		}

		bool flag = false;
		for(int i=0; i<v.size()-1; i++){
			if(abs(v[i]-v[i+1]) >= 2){
				flag = true;
				cout << "YES" << endl;
				cout << i+1 << " " << i+2 << endl;
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
	}


	exit(0);
}
