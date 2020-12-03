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

int n;
vector<int> v;
bool dp[(int)1e6+10][102];
bool vis[(int)1e6+10];

void solve(int at, int pos){
	vis[at] = 1;
	if(pos==n) return;
	if(dp[at][pos]) return;
	dp[at][pos] = 1;
	solve(at+v[pos], pos+1);
	solve(at, pos+1);
}

int main(){ _
	cin >> n;
	v.resize(n);
	ll sum = 0;
	for(auto &i : v) cin >> i, sum+=i;
	solve(0, 0);	
	vector<int> w;
	for(int i=0; i<(int)1e6+5; i++) if(vis[i]) w.pb(i); 

	ll ans = 0;
	for(auto u : w){
		ans += 2*(sum-u+1);
		int inter = upper_bound(w.begin(), w.end(), sum-u) - w.begin();
		ans -= inter;
	}
	cout << ans << endl;
		
	
	
	exit(0);
}
