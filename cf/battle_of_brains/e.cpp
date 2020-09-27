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
	int cs = 0;
	vector<ll> p2;
	p2.pb(1ll);
	for(int i=1;i <61; i++){
		p2.pb(p2[i-1]*(ll)2); 
	}
	while(t--){
		cs++;
		cout << "Case " << cs << ": ";
		ll d, x; cin >> d >> x;
		ll at=0;
		int ans = 0;
		while(d>-1){
			if(at>x) at -= (p2[d]);
			else if(at==x) break;
			else at += (p2[d]);
			ans++;
	//		cout << d << " " << at << endl;
			d--;
		}
		if(at==x) cout << "YES " << ans << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
