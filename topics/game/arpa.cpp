#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

unordered_map<int, int> dp;
int msb(int x) {
	return __builtin_clz(1)-__builtin_clz(x);
}
int solve(int mask){
	if(mask<=1) return 0;
	if(dp.count(mask)) return dp[mask];
	int maxi = msb(mask);
	vector<int> mex;
	for(int i=1; i<=maxi; i++){
		int at = mask;
		for(int j=i; j<=maxi; j++) if(mask&(1<<j)){
			at ^= (1<<j);
			if(i!=j) at |= (1<<(j-i));
		}
		mex.pb(solve(at));
	}
	sort(mex.begin(), mex.end());
	vector<int>::iterator it = unique(mex.begin(), mex.end());
	mex.resize(distance(mex.begin(), it));	
	
	int g = 0;
	int i = 0;
	for(auto k : mex){
		if(g==k) g++;
		else break;
	}
	return dp[mask]=g;
}

int main(){ _
	int n; cin >> n;
	map<int, vector<int>> mp;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		for(int i=2; i*i<=a; i++) if(a%i==0){
			int at = 0;
			while(a%i==0) a/=i, at++;
			mp[i].pb(at);
		}
		if(a!=1) mp[a].pb(1);
	}
	int ans = 0;
	for(auto x : mp){
		sort(x.s.begin(), x.s.end());
		vector<int>::iterator it = unique(x.s.begin(), x.s.end());
		x.s.resize(distance(x.s.begin(), it));
	
		int at = 0;
		for(int k : x.s) {
			at += 1<<k;
		}
		ans ^= solve(at);
	}
	if(ans==0) cout << "Arpa" << endl;
	else cout << "Mojtaba" << endl;



	exit(0);
}
