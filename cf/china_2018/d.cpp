#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 55;

ld n, m;

ld memo[MAX][MAX][2]; // posicao atual | onde duha sentou | m ou n

ld dp1(int pos, int duha) {
	if(pos==n-1){
		return 0;
	}

	ld &ret = memo[pos][duha][0];
	if(ret>-0.5) return ret;
	ret = 1.0/(n-pos);
	for(int i=pos+1; i<n; i++){
		ret = ret + 1.0/(n-pos)*dp1(i, i);
	}
	return ret;
}

ld dp2(int pos, int duha) {
	if(pos==m-1){
		return 0;
	}

	ld &ret = memo[pos][duha][1];
	if(ret>-0.5) return ret;
	ret = 1.0/(m-pos);
	for(int i=pos+1; i<m; i++){
		ret = ret + 1.0/(m-pos)*dp2(i, i);
	}
	return ret;
}

int main(){ _

	int t; cin >> t;

	for(int tcase = 1; tcase <= t; tcase++) {
		cin >> n >> m;
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) for(int k=0; k<2; k++)
			memo[i][j][k] = -3;

		ld ans1;
		if(n>1) ans1 = dp1(0, 0);
		else ans1 = 1;
		
		ld ans2=1;
		if(m>1){
			for(int i=0;i <m; i++)
				ans2 -= 1.0/m*dp2(i, i);
		}

		cout << fixed << setprecision(6);
		cout << "Case #" << tcase << ": " << ans1 << ' ' << ans2 << endl;
	}

	return 0;
}

