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

ll solve(vector<ll> v){
	int n = v.size();
	if(n==0) return 0;
	map<ll, int> ma;
	ma[0] = 0;


	vector<ll> s;
	s.pb(v[0]);
	for(int i=1;i <v.size(); i++){
		s.pb(v[i]+s[i-1]);
	}

//	for(int i=0; i<s.size(); i++) cout << s[i] <<" ";
//	cout << endl;

	ll ans = 0; int at = 0;
	for(int i=1;i <=s.size(); i++){
		if(!ma.count(s[i-1])){
			ans += i-at;
			ma[s[i-1]] = i;
		}
		else{
			at = max(at, ma[s[i-1]]+1);
			ma[s[i-1]] = i;
			ans += i-at;
		}
	}

	return ans;
}

int main(){ _
	// use ll

	ll n; cin >> n;
	vector<ll> v;
	ll ans = 0;
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		if(a==0) {
			ans += solve(v);
			v.resize(0);
			continue;
		}
		v.pb(a);
	}
	ans += solve(v);
	cout << ans << endl;
	
	
	
	exit(0);
}
