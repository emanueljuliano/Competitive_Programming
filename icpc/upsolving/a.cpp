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


int main(){ _
	int n, a, b; cin >> n >> a >> b;
	
	vector<double> dp(n+10);
	vector<double> pref(n+10);

	double raz = b-a+1;
	dp[0] = 0;
	double sum = 0;
	for(int i=1;i <=n; i++){
		if(a!=0){
			dp[i] = 1.0 + sum/raz;
			sum += dp[max(0, i-a+1)] - dp[max(0, i-b)];
		}
		else{
			// x_i = 1 + x_i/raz + sum/raz
			// x_i(1-1/raz) = 1 + sum/raz
			// x_i = (1+sum/raz)/(1-1/raz);
			dp[i] = (raz + sum)/(raz-1);
			sum += dp[i] - dp[max(0, i-b)];
		}
	}
	cout << setprecision(6) << fixed;	
	cout << dp[n] << endl;
	
	exit(0);
}
