#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = 1;
		for(int i=1; i*i<=n; i++) if(n%i==0){
			for(int j=2; j<31; j++){
				if(i == (1<<j)-1){
					ans = i;
					break;
				}
			}
			if(ans!=1) break;
			for(int j=2; j<31; j++){
				if(n/i == (1<<j)-1){
					ans = n/i;
					break;
				}
			}

			if(ans!=1) break;
		}
		cout << n/ans << endl;
	}
	
	
	
	exit(0);
}
