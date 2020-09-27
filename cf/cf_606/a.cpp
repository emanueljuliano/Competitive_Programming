#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string t;
		cin >> t;
		
		int ans = 0;
		ans += (t.size()-1)*9;
		bool flag = false;

		for(int j=0; j<(int)t.size()-1; j++){
			//cout << t[] << " aqui " << t[1] << endl;
			if(t[j]<t[j+1]) break;	
			else if(t[j]>t[j+1]) {flag = true; break;}
		}
		
		ans += t[0] -'0';
		//cout << t << " " << t[0] -'0' << " " << flag << endl;
		if(flag) ans--;
		cout << ans  << endl; 
			
	}

	exit(0);
}
