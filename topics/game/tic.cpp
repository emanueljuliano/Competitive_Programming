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

int dp[(int)1e4+10];
vector<int> g(300, 0);
int main(){ _
	int n;
	dp[0] = 0;
	set<int> st;
	int maxi = 0;
	for(int i=1; i<=(int)1e4; i++){
		for(int j=0;j <300; j++) g[j] = 0;
		for(int j=1; j<=i/2+i%2; j++){
			int a = max(0, j-3);
			int b = max(0, i-j-2);
			g[dp[a]^dp[b]]=1;
		}
		int mex = 0;
		while(g[mex])mex++;
		dp[i] = mex;
	}
//	for(int i=0;i <15; i++) cout << i << " " << dp[i] << endl;
	while(true){ cin >> n; if(n==0) break;
		int ans = 0, at = 0;
		string s; cin >> s;	
		
		for(int i=0;i <n-2; i++){
			int x = 0;
			for(int j=i; j<i+3; j++) if(s[j]=='X')x++;
			if(x>=2) ans = INF;
		}

		vector<int> xis;
		for(int i=0;i <n; i++) if(s[i]=='X') xis.pb(i);
		for(auto i : xis)
			for(int j=max(0, i-2); j<=min(n-1, i+2); j++) s[j]='X';
		
//		cout << s << endl;
		
		for(int i=0;i <s.size(); i++){
			if(s[i]=='X'){
				ans ^=dp[at];
				at = 0;
			}
			else at++;
		}
		ans ^= dp[at];
		if(ans==0) cout << "N" << endl;
		else cout << "S" << endl;
	}
	
	
	
	exit(0);
}
