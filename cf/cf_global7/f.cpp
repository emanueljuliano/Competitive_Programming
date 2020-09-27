#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int M[15][15];
ll dp[16401][14];
int calc[16401][14];
int n;

ll rec(int mask, int mens, int c){
	if(mens == (1<<n)-1) return 1;
	if(calc[mens][c] == mask)
		return dp[mens][c];
	
	ll ans = 0;
	for(int i=0; i<n; i++){
		if((mask & 1) == M[c][i] and !(mens & 1<<i)){
			ans += rec(mask>>1, mens + (1<<i), i);
		}
	}
	
	calc[mens][c] = mask;
	return dp[mens][c] = ans;
}

int main(){ _
	memset(calc, -1, sizeof(calc));
	
	cin >> n;	
	for(int i=0; i<n; i++){
		string s; cin >>s;
		for(int j=0; j<n; j++){
			M[i][j] = s[j]-'0';
		}
	}
	
	for(int i=0; i<1<<(n-1); i++){
		ll ans = 0;
		int mask = i;
		for(int j=0; j<n; j++){
			ans += rec(mask, 1<<j, j);
		}
		cout << ans << " ";
	}
	cout << endl;
	exit(0);
}
