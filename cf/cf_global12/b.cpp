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

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<ii> v(n);
		for(auto &i:v) cin >> i.f >> i.s;

		bool show = false;
		for(int i=0;i <n; i++){
			show = true;
			for(int j=0; j<n; j++){
				if(abs(v[i].f-v[j].f) + abs(v[i].s-v[j].s) > k) show = false;
			}
			if(show) break;
		}
		if(show) cout << 1 << endl;
		else cout << -1 << endl;
	}
	
	
	
	exit(0);
}
