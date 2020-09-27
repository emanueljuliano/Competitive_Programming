#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	while(true){
		cin >> n;
		if(n==0) break;
		bool pode = false;
		int ans = 0;
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			if(b%4>=2 and pode) ans++, pode=false;
			else if(b%4>=2) pode=true;
			ans += b/= 4;
		}
		cout << ans << endl;
	}


	exit(0);
}
