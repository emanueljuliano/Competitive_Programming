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

const int MOD = 1e9+7;

string s;
ll dp[55][55];
ll rec(int l, int r){
	if(l==r or l==r+1) return 1;
	if(l>r) return 0;

	ll &ret = dp[l][r];
	if(ret!=-1) return ret;
	ret = 1;

	int la = 0;
	for(int i=l;i<r; i++){
		la += s[i]-'0';
		int lb = 0;
		for(int j=r; j>i; j--){
			lb += s[j]-'0';
			if(la==lb){
				ret = (ret + rec(i+1, j-1))%MOD;
			}
			if(lb>la) break;
		}
	}
	return ret;
}


int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> s;
		for(int i=0;i <s.size(); i++) for(int j=0; j<s.size(); j++) dp[i][j] = -1;
		cout << rec(0, s.size()-1) << endl;
	
	}
	
	
	
	exit(0);
}
