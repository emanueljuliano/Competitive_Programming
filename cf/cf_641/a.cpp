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
		ll n, k; cin >> n >> k;
		ll s = -1;
		while(k and s!=2){
			s = -1;
			for(ll i=2;i*i<=n; i++){
				if(n%i==0){s = i; break;}
			}
			if(s==-1) s = n;
			n += s;
			k--;
		}
		n += s*k;
		cout << n << endl;
	
	}
	
	
	
	exit(0);
}
