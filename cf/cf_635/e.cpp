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
const int MOD = 998244353;

string s, t;
map<string, ll> dp;

ll rec(string at){
	if(dp.count(at)) return dp[at];
	ll &ans = dp[at];

	int x = at.size();
	bool eq = false;
	if(x>=t.size()){
		eq = true;
		for(int i=0; i<t.size(); i++){
			//if(eq)cout << at << endl;	
			if(t[i]!=at[i]){ eq=false; break;}
		}
	}
	if(eq){
	//	cout << at << endl;
		ans++;
	}
	if(x==s.size()) return ans;

	ans = (ans +  rec(s[x]+at))%MOD;
	at += s[x];
	ans = (ans + rec(at))%MOD;
	return ans;
}

int main(){ _
	cin >> s >> t;
	ll ans = rec("");
	cout << ans << endl;
	
	
	exit(0);
}
