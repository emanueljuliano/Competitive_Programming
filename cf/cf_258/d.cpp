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

const int MAX = 1e5+10;
ll dp[MAX][3][3]; // pos, char, parity

int main(){ _
	string s; cin >> s;
	int n = s.size();
	if(s.back()=='a') dp[n-1][0][1] = 1;
	if(s.back()=='b') dp[n-1][1][1] = 1;
	int at = s.back()-'a';
	int cnt = 1;
	for(int i=n-2; i+1; i--){
		//cout << i << " " << s[i] << " " << at << endl;
		if((s[i]-'a')==at) {
		//	cout << "equal" << endl;
			dp[i][at][0] = dp[i+1][at][1];
			dp[i][at][1] = dp[i+1][at][0] + 1;
			cnt++;
		}
		else{
			at = s[i]-'a';
		//	cout << "dif" << endl;
			dp[i][at][0] = dp[i+1+cnt][at][1^(cnt%2)];
			dp[i][at][1] = dp[i+1+cnt][at][0^(cnt%2)] + 1;
			cnt = 1;
		}
		//cout << "dp " <<  dp[i][at][0] << " " << dp[i][at][1] << endl;
	}
	
	ll even = 0, odd=0;
	for(int i=0;i <n; i++) for(int j=0; j<2; j++) even += dp[i][j][0];
	for(int i=0;i <n; i++) for(int j=0; j<2; j++) odd += dp[i][j][1];
	
	cout << even << " " << odd << endl;
	
	exit(0);
}
