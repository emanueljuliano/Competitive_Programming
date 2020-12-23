#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;

	int nxt = n;
	for(int i=n; i<=2000; i++){
		bool is_prime = true;
		for(int j=2; j*j<=i; j++) if(i%j==0) {is_prime=false; break;} 
		if(is_prime) {nxt = i; break;}
	}

	vector<ii> ans;
	for(int i=1; i<n; i++) ans.pb({i, i+1});
	ans.pb({n, 1});
	
	while(ans.size()<nxt){
		for(int i=1; i<n; i+=4){
			ans.pb({i, i+2});
			if(ans.size()==nxt) break;
			ans.pb({i+1, i+3});
			if(ans.size()==nxt) break;
		}
	}

	cout << ans.size() << endl;
	for(auto [a, b] : ans) cout << a << " " << b << endl;


	exit(0);
}
