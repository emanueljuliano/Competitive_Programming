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
		int n; cin >> n;
		string a, b; cin >> a >> b;
		int ini = 0, fim = n-1;
		string va, vb;
		for(int i=0;i <n; i++) if(a[i]!=b[i]){va.pb(a[i]), vb.pb(b[i]);}
		if(va.empty()){
			cout << "YES" << endl;
			continue;
		}
		vb = vb.back() + vb;
		vb.pop_back();
		if(va==vb) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
