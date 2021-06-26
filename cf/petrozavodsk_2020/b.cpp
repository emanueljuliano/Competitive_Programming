#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N = log2(1e6)+2;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> A(1<<N), F(1<<N);
		for(int i=0;i <n; i++){
			int a; cin >> a; A[a]++;
		}
		for(int i=0; i<(1<<N); ++i) F[i] = A[i];
			
		for(int i=0;i <N; ++i) for(int mask = 0; mask<(1<<N); ++mask){
			if(mask & (1<<i)) F[mask] += F[mask^(1<<i)];
		}
		ll ans = 0;
		for(int i=0;i <(1<<N); i++) ans += A[i]*(ll)F[i];
		cout << ans << endl;

	}
	
	
	
	exit(0);
}
