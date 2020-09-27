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
		vector<int> v(n), w(n);
		for(auto &i : v) cin >> i;
		for(auto &i : w) cin >> i;
		bool show = true;
		for(int i=1; i<v.size(); i++){
			if(v[i]<v[i-1]) show = false;
		}
		int z=0, o=0;
		for(int i=0;i <v.size(); i++){
			if(w[i]==0) z++;
			else o++;
		}
		if(o!=0 and z!=0) show = true;
		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
