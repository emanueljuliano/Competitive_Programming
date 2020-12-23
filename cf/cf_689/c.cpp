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
		int n, m; cin >> n >> m;
		vector<int> v(n);
		for(int i=0;i <n; i++) cin >> v[i];
		int pos = 0;
		for(int i=n-1; i+1; i--) if(v[i]!=i+1){pos=i+1; break;};
		double ans = 0.0;
		double carry = 1;
		for(int i=0;i <m; i++){
			int a; double d; cin >> a >> d;
			if(a<pos) continue;
			ans += carry*d;
			carry *=(1.0-d);
		}
		cout << setprecision(6) << fixed;
		if(pos==0){
			cout <<	1.0 << endl;
			continue;
		}

		cout << ans << endl;
	}
	
	
	
	exit(0);
}
