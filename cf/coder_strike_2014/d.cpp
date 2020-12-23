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

const int MOD = 1e9+7;
const int MAX = 5e3 + 100;
int dp[MAX][MAX][2];
vector<int> v;
int n, k;

int solve(int pos, int msk, int show){
	msk = (!show)*msk;
	//cout << pos << " " << msk << " " << show << endl;
	if(pos==n) return show;
	int &ret = dp[pos][msk][show];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=1; i<=2; i++){
		int at = i;
		if(v[pos] != 0) at = v[pos]/2;
		int msk2 = msk;
		if(at==2 and (msk2 & (2))) {
			ret = (ret + solve(pos+1, 4, show))%MOD;
		}
		else{
			for(int j=at;j <=k; j++){
				if(msk2 & (1<<at)) msk2-=(1<<at), at++;
				else {msk2+=(1<<at); break;};
			}
			ret = (ret + solve(pos+1, msk2, show or at>=k))%MOD;
		}
		if(v[pos] != 0) break;;
	}
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof dp);
	cin >> n >> k;

	v.resize(n);
	for(auto &i: v) cin >> i;
	cout << solve(0, 0, 0) << endl;
	
	
	exit(0);
}
