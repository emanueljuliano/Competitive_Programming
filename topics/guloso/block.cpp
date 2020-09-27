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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		vector<int> v(n);
		for(auto &i:v) cin >> i;
		bool flag = true;
		for(int i=0;i <n-1; i++){
			m += v[i] - max(v[i+1]-k, 0);
			if(m<0) flag = false;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	
	
	}
	
	
	
	exit(0);
}
