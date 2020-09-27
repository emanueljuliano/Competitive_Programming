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
		vector<int> v;
		set<int> se;
		vector<ii> w;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
			se.insert(a);
			w.pb({a, i});
		}

		vector<int> ret(2*n, -1);
		bool flag = true;
		for(int i=0;i <w.size(); i++){
			ret[2*w[i].s] = w[i].f;
			int at = -1;
			for(int j=w[i].f+1; j<=2*n; j++){
				if(!se.count(j)){
					at = j;
					se.insert(at);
					break;
				}
			}
			if(at==-1) flag = false;
			ret[2*w[i].s+1] = at;
		}
		if(!flag){
			cout << -1 << endl;
			continue;
		}
		else{
			for(int i=0; i<2*n; i++){
				cout << ret[i] << " ";
			}
			cout << endl;
		}


	}
	
	
	
	exit(0);
}
