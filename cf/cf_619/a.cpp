#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		string a, b, c;
		cin >> a >> b >> c;
		bool flag = true;
		for(int i=0; i<a.size(); i++){
			if(c[i]!=a[i] and c[i]!=b[i]){
				flag = false;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}


	exit(0);
}
