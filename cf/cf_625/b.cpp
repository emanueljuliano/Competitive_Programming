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
	int n;cin >> n;
	vector<int> v;
	map<int, ll> b;
	for(int i=0; i<n; i++){
		ll a; cin >> a;
		v.pb(a);
		b[a-i+200010]+= a;
	}
	ll maxi = 0;
	for(auto x : b){
		maxi = max(maxi, x.s);
	}
	cout << maxi << endl;
	
	exit(0);
}
