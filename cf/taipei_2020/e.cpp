#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

string s;
int n;
int dp[555][555];
int solve(int l, int r){
	int &ret = dp[l][r];
	if(ret != -1) return ret;

	int show = true;
	for(int i=l;i<r; i++) if(s[i]!=s[l]) show = false;
	if(show) return ret = r-l;

	ret = 0;
	for(int i=l+1; i<r; i++){
		if(solve(i, r)>=n) ret = max(ret, solve(l, i));
		if(s[l]==s[i] and solve(i, r)>0 and solve(l, i)>0) 
			ret = max(ret, solve(i, r) + solve(l, i));
	}
	return ret;
}

int main(){ _
	cin >> s;
	cin >> n;
	memset(dp, -1, sizeof dp);
	if(solve(0, s.size()) >=n) cout << "Yes" << endl;	
	else cout << "No" << endl;
	
	
	exit(0);
}
