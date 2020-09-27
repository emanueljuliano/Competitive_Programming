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
		string s;
		cin >> s;
		int at=0;
		int ans=0;
		bool flag=false;
		for(int i=0; i<n; i++){
			if(s[i]=='A' and !flag){
				flag=true;
			}
			else if(s[i]=='P' and flag){
				at++;
				ans = max(ans, at);
			}
			else if(s[i]=='A' and flag){
				ans = max(ans, at);
				at=0;
			}
		}
		cout << ans << endl;
	}


	exit(0);
}
