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
		int n, m; cin >> n >> m;
		bool show = false;
		
		for(int i=0;i <n; i++){
			int a, b, c, d; cin >> a >> b >> c >> d;
			if(b==c) show = true;
		}
		if(show and !(m%2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	
	exit(0);
}
