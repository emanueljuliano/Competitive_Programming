#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ii> v(n);
		for(auto &i: v) cin >> i.f >> i.s;
		int k, r; cin >> k >> r;
		
		vector<int> dp(k+1);
		for(int i=0;i <n; i++) for(int j=k; j; j--) if(v[i].s<=j)
			dp[j] = max(dp[j], dp[j-v[i].s]+v[i].f);
			
		if(dp[k] >= r) cout << "Missao completada com sucesso" << endl;
		else cout << "Falha na missao" << endl;
	}

	exit(0);
}
