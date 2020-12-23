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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<ii> v;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		ll sq = sqrt(a)+1e-9;
		if(sq*sq < a) v.pb({min(a-sq*sq, (sq+1)*(sq+1)-a), a});
		else v.pb({0, a});
	}

	sort(v.begin(), v.end());
	
	ll ans = 0;
	if(v[n/2].f==0){
		for(int i=n/2; i<n and v[i].f==0; i++){
			if(v[i].s==0) ans += 2;
			else ans++;
		}
		cout << ans << endl;
	}
	else{
		for(int i=n/2-1; i+1 and v[i].f!=0; i--)
			ans += v[i].f;
		cout << ans << endl;
	}
	
	
	exit(0);
}
