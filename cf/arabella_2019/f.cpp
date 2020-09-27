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

vector<int> v, w;
int dp[1010][1010];
int n;
int solve(int at, int it, int MOD){
	if(it == n-1) return true;
	
	int &ret = dp[at][it];
	if(ret!=-1) return ret;
	ret = false;
	
	int pa = (at+v[it])%MOD; 
	int pb = ((at-v[it])%MOD+MOD)%MOD;
//	cout << at << " " << it << " " << MOD << endl;
//	cout << "at = " << at << " vai pra " << pa << " " << pb << endl;
	if(pa != w[it]){
		pa -= w[it]<pa;
		ret |= solve(pa, it+1, MOD-1);
	}
	if(pb != w[it]){
		pb -= w[it]<pb;
		ret |= solve(pb, it+1, MOD-1);
	}
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof(dp));
	int p; cin >> n >> p; p--;
	for(int i=0;i <n-1; i++){
		int a; cin >> a; v.pb(a);
	}
	for(int i=0;i <n-1; i++){
		int a; cin >> a; a--; w.pb(a);
	}
	for(int i=0;i <n-1; i++){
		int a = w[i];
		for(int j=i+1; j<n-1; j++){
			if(w[j]>a) w[j]--;
		}
	}

	bool show = solve(p, 0, n);
	if(show) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	exit(0);
}
