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
		ll n; cin >> n;
		int ans = 0;
		while(n>1){
			if(n%2 and n%3 and n%5){ans = -1; break;}
			while(n%2==0) n/=2, ans++;
			if(n%3==0) n/=3, n*=2, ans++;
			else if(n%5==0) n/=5, n*=4, ans++;
		}
		cout << ans << endl;
	
	}

	exit(0);
}
