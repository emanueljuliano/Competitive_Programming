#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int sz(int mask){
	return __builtin_popcount(mask);
}

int main(){ _
	int n;
	double k; cin >> n >> k;
	int sa = n/2, sb = n-sa;

	vector A(n, vector<int>(n));
	for(auto &r : A) for(auto &l : r) cin >> l;
	
	vector<int> adja, adjb;
	for(int i=0;i <n; i++){
		int mask = 0;
		for(int j=0; j<sa; j++)
			if(A[i][j]) mask|=(1<<j);
		adja.push_back(mask);
		mask = 0;
		for(int j=sa; j<n; j++)
			if(A[i][j]) mask|=(1<<(j-sa));
		adjb.push_back(mask);
	}
	
	vector<int> dp((1<<(n/2)));
	int ans = 0;
	for(int mask=1; mask<(1<<sa); mask++){
		int at = 0;
		for(int j=0; j<n/2; j++) if(mask & (1<<j)){
			int clique = dp[mask^(1<<j)];
			if(!at) at = 1<<j;
			if(sz(at) <= sz(clique)){
				at = clique;
				if((adja[j]&clique) == clique)
					at = clique|(1<<j);
			}
		}
		dp[mask] = at;
		ans = max(ans, sz(at));
	}

	for(int mask = 1; mask<(1<<sb); mask++){
		int cur = mask;
		int adj = (1<<sa)-1;
		for(int j=0; j<sb; j++) if(mask & (1<<j)){
			cur &= (adjb[j+sa] | (1<<j));
			adj &= adja[j+sa];
		}
		if(cur == mask){
			ans = max(ans, sz(cur) + sz(dp[adj]));
		}
	}
	cout << fixed << setprecision(7) << (k/ans)*(k/ans)*ans*(ans-1)/2 << endl;
	

	
	
	
	exit(0);
}
