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
	int n, m; cin >> n >> m;
	set<int> ans;
	vector<int> v(n), w(m);
	for(auto &i : v) cin >> i;
	for(auto i : v) ans.insert(i);
	for(auto &i : w) cin >> i;
	map<int, vector<int>> M;
	for(int i=1; i<(1<<m); i++){
		int at = 0;
		for(int j=0; j<m; j++) if((1<<j)&i){
			at += w[j];
		}
		M[at].pb(i);
	}
	for(auto x : M){
		//cout << x.f << " = ";
		//for(auto k : x.s) cout << k << " ";
		//cout << endl;
		bool add = false;
		for(int j=0; j<x.s.size(); j++)for(int i=j+1; i<x.s.size(); i++){
			int orr = x.s[i]|x.s[j];
			int sum = x.s[i]+x.s[j];
			if(orr==sum){
		//		cout << x.s[0] << " <-z  at->"<<x.s[i] << endl;
		//		cout << "xor = " << xo << " sum = " << sum << endl;
				add = true; break;
				
			}
		}
		if(add) for(int i=0;i <n; i++) ans.insert(2*x.f+v[i]);
	}
	for(auto i :ans) cout << i << endl;
	exit(0);
}
