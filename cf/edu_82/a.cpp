#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int ans = 0, at = 0;
		bool flag = false;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='1') flag = true;
			if(flag){
				if(s[i]=='0') at++;
				else{ ans += at; at = 0;}
			}
		}
		cout << ans << endl;
	}

	exit(0);
}
