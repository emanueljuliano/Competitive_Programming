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
	double c; cin >> c;
	ll x = c*10000;
	int at = 10;
	vector<int> ans;
	for(ll i=1; i<(int)1e8; i++){
		if(i>=at) at *= 10;
		ll ni = i*x;
		if(ni%10000) continue;
		ni = ni/10000;
		if(ni>=at) continue;
		if(ni%10 == i/(at/10) and i%(at/10)==ni/10) ans.pb(i);
	}
	if(!ans.size()) cout << "No solution" << endl;
	else{
		for(auto b : ans) cout << b << endl;
	}
	
	
	exit(0);
}
