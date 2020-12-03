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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=1; i<=n; i++) v.pb(i);

		vector<ii> ans;
		while(v.size()>1){
			int a = v.back(); v.pop_back();
			int b = v.back(); v.pop_back();
			if(v.empty()) v.pb((a+b+1)/2), ans.pb({a, b});
			else{
				if(a%2==b%2) v.pb((a+b+1)/2), ans.pb({a, b});
				else{
					int c = v.back(); v.pop_back();
					if(c%2==a%2) v.pb(b), v.pb((a+c+1)/2), ans.pb({a, c});
					else v.pb(a), v.pb((b+c+1)/2), ans.pb({b, c});
				}
			}
		}
		cout << v[0] << endl;
		for(auto [a, b] : ans) cout << a << " " << b << endl;
	}
	
	
	
	exit(0);
}
