#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> v;
double dp[5050][5050];

double solve(int i, int t){
	if(i<0) return 0;
	if(t>i+1) return 0;
	
	double &ret = dp[i][t];
	if(ret > -1) return ret;
	ret = 0;
	
	double p = double(t)/(i+1);
	if(t) ret = p*solve(i-1, t-1);
	ret += (1-p)*(solve(i-1, t+1) + v[i]);
	return ret;
}

int main(){ _
	cin >> n;
	v.resize(n);
	double sum = 0;
	for(auto &i : v) cin >> i, sum += i;
	for(int i=0;i <n; i++) for(int j=0; j<n; j++) dp[i][j] = -5;
	sort(v.begin(), v.end());


	double d = solve(n-1, 0);
	cout << setprecision(10) << fixed;
	cout << d << " " << sum-d << endl;
	
	
	exit(0);
}
