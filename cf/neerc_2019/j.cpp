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

const int MAX = 26;
const int MAX_CAP = 3e4+10;

int v[MAX], w[MAX];
int dp[2][MAX_CAP];

void get_dp(int x, int l, int r, int cap){
	memset(dp[x], 0, (cap+1)*sizeof(dp[x][0]));
	for(int i=l; i<=r; i++) for(int j=cap; j>=0; j--)
		if(j-w[i] >= 0) dp[x][j] = max(dp[x][j], v[i]+dp[x][j-w[i]]);
}

void solve(vector<int> &ans, int l, int r, int cap){
	if(l==r){
		if(w[l] <= cap) ans.pb(l);
		return;
	}
	int m = (l+r)/2;
	get_dp(0, l, m, cap), get_dp(1, m+1, r, cap);
	int left_cap = -1, opt = -INF;
	for(int j=0; j<=cap; j++)
		if(int at = dp[0][j] + dp[1][cap-j]; at>opt)
			opt = at, left_cap = j;
	solve(ans, l, m, left_cap), solve(ans, m+1, r, cap-left_cap);
}

vector<int> knapsack(int n, int cap){
	vector<int> ans;
	solve(ans, 0, n-1, cap);
	return ans;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		string s; cin >> s;
		for(int i=0;i <26; i++) v[i]=0, w[i]=0;
		for(auto c : s) v[c-'A']++, w[c-'A']++;

		
		ll ans = ll(k)*ll(k); 

		for(int tt=0;tt <2; tt++){
			vector<int> va = knapsack(26, n);
			vector<int> res;
			int pa = 0;
			vector<int> vis(26);
			for(auto u : va) vis[u] = 1;
			
			for(int i=0;i <26; i++) {
				if(!vis[i] and v[i]) res.pb(v[i]);
				else pa += v[i];
			}
			//for(auto u : res) cout << u << " ";
			//cout << endl;
			sort(res.begin(), res.end());

			int at = 0;
			for(int i=1; i<res.size(); i++) at += res[i];
			if(at>=m) ans = 0;
			else ans = min(ans, ll(n-pa)*ll(m-at));
	
			swap(m, n);
		}
		
		cout << ans << endl;	
	}
	
	exit(0);
}
