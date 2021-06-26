#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6+10;
int n, k;
vector<int> v, nxt, nxt2, ans;
int dp[MAX];

int solve(int i){
	if(i==n) return dp[i] = 0;

	int &ret = dp[i];
	if(ret != -1) return ret;

	// remove i
	ret = 1 + solve(nxt[i]);
	// don't remove i
	if(v[i] != k) ret = min(ret, solve(nxt2[i]));
	
	return ret;
}

void rec(int i){
	if(i==n) return;

	if(dp[i] == 1 + dp[nxt[i]]){
		ans.push_back(i);
		return rec(nxt[i]);
	}
	return rec(nxt2[i]);
}

int main(){ _
	cin >> n >> k;
	v.resize(n);
	nxt = nxt2 = vector<int>(n, n);
	vector<int> last(k+1, -1);
	vector<vector<int>> stk(k+1);
	int first = n;
	
	for(int i=0;i <n; i++){
		cin >> v[i];
		if(v[i]==1 and first == n) first = i;

		// nxt[i] = next element with same value as v[i]
		if(last[v[i]] != -1) nxt[last[v[i]]] = i;
		last[v[i]] = i;
		
		// nxt2[i] = next element with value of v[i] + 1
		while(stk[v[i]-1].size()) 
			nxt2[stk[v[i]-1].back()] = i, stk[v[i]-1].pop_back();

		stk[v[i]].push_back(i);
	}
	
	memset(dp, -1, sizeof dp);
	solve(first);	
	rec(first);

	cout << ans.size() << endl;
	for(auto u : ans) cout << u+1 << " ";
	cout << endl;
	exit(0);
}
