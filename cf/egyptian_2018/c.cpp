#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 1e15;

const int MAX = 4e3+10;
ll dp[MAX][MAX];
ll pref[MAX][MAX], suf[MAX][MAX];
int A[MAX], B[MAX], C[MAX];

int n, m;

ll solve(int i, int j) {
	ll &ret = dp[i][j];
	if (ret != -LINF) return ret;
	ret = LINF;
	
	if (j == m) {
		ret = 0;
		for (int k=i; k<n; k++) ret += C[k];
		return ret;
	}
	if (i == n) return ret; 
	

	if (A[i] == B[j]) ret = min(ret, solve(i+1, j+1));
	if (j == 0 or pref[j-1][A[i]] == 0) ret = min(ret, C[i] + solve(i+1, j));
	if (suf[j][A[i]] == 0) ret = min(ret, C[i] + solve(i+1, j));

//	cout << i << " " << j << " ai " << A[i] << " bi " << B[i] << " suf " << suf[j][A[i]] << " ret " << ret<< " ci " << C[i] <<  endl;

	return ret;
}


int main(){ _
	#warning FILE IN 
   	freopen("transform.in", "r", stdin);	
	
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = -LINF;
		memset(suf, 0, sizeof suf);
		memset(pref, 0, sizeof pref);

		map<int, int> mp;
		int pt = 0;
		for (int i=0; i<n; i++) {
			cin >> A[i];
			if (!mp.count(A[i])) mp[A[i]] = pt++;
			A[i] = mp[A[i]];
		}
		for (int i=0; i<m; i++) {
			cin >> B[i];
			if (!mp.count(B[i])) mp[B[i]] = pt++;
			B[i] = mp[B[i]];
		}
		for (int i=0; i<n; i++) cin >> C[i];

		pref[0][B[0]] = 1;
	//	cout << "pref" << endl;
		for (int i=1; i<m; i++) {
			for (int j=0; j<pt; j++) pref[i][j] = pref[i-1][j];
			pref[i][B[i]]++;

	//		for (int j=0; j<pt; j++) cout << pref[i][j] << " ";
	//		cout << endl;
		}
	//	cout << "suf" << endl;
		suf[m-1][B[m-1]] = 1;
		for (int i=m-2; i+1; i--) {
			for (int j=0; j<pt; j++) suf[i][j] = suf[i+1][j];
			suf[i][B[i]]++;
	//		for (int j=0; j<pt; j++) cout << suf[i][j] << " ";
	//		cout << endl;
		}

		ll ans = solve(0, 0);
		if (ans > 1e14) cout << "No" << endl;
		else cout << ans << endl;
	}
	
	exit(0);
}
