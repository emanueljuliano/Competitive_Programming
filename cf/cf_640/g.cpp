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
		if(n==1) {cout << 1 << endl; continue;}
		if(n<=3) {cout << -1 << endl; continue;}
		if(n==4){ cout << "3 1 4 2" << endl; continue;}
		else{
			vector<int> ans;
			ans.pb(n);
			int at = n;
			while(at!=2 and at!=1){
				at -=2;
				ans.pb(at);
			}
			if(at==1){
				ans.pb(at+=3);
				ans.pb(at-=2);
				ans.pb(at+=4);
				while(at<=n){
					at+= 2;
					ans.pb(at);
				}
			}
			else{
				ans.pb(at+=3);
				ans.pb(at-=4);
				ans.pb(at+=2);
				ans.pb(at+=4);
				while(at<=n){
					ans.pb(at+=2);
				}
			}
			for(auto k : ans){
				if(k>n) break;
				cout << k << " ";
			}
			cout << endl;
		}
	
	}


	
	
	
	exit(0);
}
