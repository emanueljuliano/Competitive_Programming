#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll n, m;
	cin >> n>>m;
	map <ll, ll> ma;
	set<ll> t;
	vector<ll> ans;
	for(int i=0; i<n; i++){
		ll a;
		cin >> a;
		t.insert(a);
		ma[a] = 1;
	}
	ll at = 1;
	ll soma = 0;
	while(true){
		for(auto it = t.begin(); it!=t.end();){
			ll p = *it;
			if(ma[p+at]==1 and ma[p-at]==1){
				t.erase(it++);
			}
			else{
				if(ma[p-at]==0){
					ma[p-at]=1;
					ans.pb(p-at);
					soma+=at;
				}
				if(ans.size()>=m) break;
				if(ma[p+at]==0){
					ma[p+at]=1;
					ans.pb(p+at);
					soma+=at;
				}
				if(ans.size()>=m) break;
				++it;
			}
		}
		if(ans.size()>=m) break;
		at++;
	}
	cout << soma << endl;
	for(int i=0; i<(int)m; i++)
		cout << ans[i] <<" ";
	cout << endl;


	exit(0);
}
