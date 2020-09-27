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
		vector <int> v, w;
		set <int> s;
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			v.pb(a);
		}
		for(int i=0; i<m; i++){
			int a;
			cin >> a;
			w.pb(a);
			s.insert(a);
		}
		ll ans=0;
		ll tira=0;
		int at=0;
		set<int> tirados;
		for(ll i=0; i<v.size(); i++){
			while(at<m and tirados.count(w[at])){
				ans+=1;
				at++;
				tira++;
			}
			if(s.count(v[i])){
				 if(v[i]==w[at]){
					ans += 1 + 2*(i-tira);
					at++;
					tira++;
				}
				tirados.insert(v[i]);
			}
	
		}
		while(at<m and tirados.count(w[at])){
			ans+=1;
			at++;
			tira++;
		}
		cout << ans << endl;
	}


	exit(0);
}
