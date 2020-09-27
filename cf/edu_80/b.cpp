#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int tc;
	cin >> tc;
	while(tc--){
		ll a;
		string b;
		cin >> a >> b;
		ll t = 0;
		for(int i=0; i<b.size(); i++){
			if(b[i]=='9')
				t++;
			else
				break;
		}
		if(t == b.size()){
			cout << a * t << endl;
		}
		else{
			cout << a*(b.size()-1) << endl;
		}
		
	}


	exit(0);
}
