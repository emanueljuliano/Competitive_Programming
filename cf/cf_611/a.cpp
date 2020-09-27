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
		int n, m;
		cin >> n >> m;
		n = n*60;
		int ans = 1440 - n - m;
		cout << ans << endl;
	}


	exit(0);
}
