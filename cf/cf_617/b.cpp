#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int t; cin >>t;
	while(t--){
		int n; cin >> n;
		int aux = n/10;
		int res = 0;
		int ans = n-n%10;
		aux += n%10;
		int at = n;
		while(true){
			int sobra = at/10 + at%10;
			if(sobra<10){
				ans += sobra;
				break;
			}
			else{
				ans += sobra-sobra%10;
				at = sobra;
			}
		}
		cout << ans << endl;
	}

	exit(0);
}
