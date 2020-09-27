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
		
	ll u, v; cin >> u >> v;
	if(u>v or (v-u)%2) return cout << -1 << endl, 0;
	if(u==v){
		if(u==0) return cout << 0 << endl, 0;
		cout << 1 << endl;
		cout << u << endl;
		exit(0);
	}

	ll a1 = u;
	ll a2 = (v-u)/2;
	if((a1^a2) == (a1+a2)) a1+= a2;
	vector<ll> ans;
	
	if(a1!=0) ans.pb(a1);
	ans.pb(a2);
	if(!(a1^a2==u and a1+a2==v)) ans.pb(a2);
	
	
	if(ans.size()==1 and ans[0] == 0) return cout << 0 << endl, 0;
	cout << ans.size() << endl;

	for(int i=0;i <ans.size(); i++) cout << ans[i] << " ";
	cout << endl;

	exit(0);
}
