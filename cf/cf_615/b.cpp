#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ss second
#define ff first

typedef pair<int, int> pii;
typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pii> v;
		for(int i=0; i<n; i++){
			int a, b; cin >> a >> b;
			v.pb({a, b});
		}
		sort(v.begin(), v.end());

		bool flag = false;
		for(int i=0; i<n-1; i++){
			if(v[i].ss>v[i+1].ss) flag = true;	
		}
		if(flag){cout << "NO" << endl; continue;}
		int x = 0, y=0;
		cout << "YES" << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<v[i].ff-x; j++){
				cout <<"R";
			} 
			x= v[i].ff;
			for(int j=0; j<v[i].ss-y; j++){
				cout <<"U";
			}
			y = v[i].ss;
		}
		cout << endl;
	}


	exit(0);
}
