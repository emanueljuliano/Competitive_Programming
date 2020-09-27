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
		int n, d;
		cin >> n >> d;
		if (d<=n)
			cout << "YES" << endl;
		else{
			int ans = d;
			for(int i=1; i*i<=d; i++){
				if (d%(i+1)==0){
					ans = min(ans, i+ d/(i+1));
				}
				else{
					ans = min(ans, i+d/(i+1) +1);
				}
			}
			if (ans<= n)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}


	exit(0);
}
