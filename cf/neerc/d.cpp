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
	int n; cin >> n;
	vector<int> v;
	map<int, int> ma;
	for(int i=0;i<n; i++){
		int a; cin >> a;
		v.pb(a);
		ma[a]++;
	}
	map<int, vector<int>> ans;
	bool flag = true;
	for(auto x : ma){
		ans[x.f].pb(1);
		if(x.f!=1) ans[x.f].pb(x.f);
		if(x.s>2){
			for(int i=2; i*i<=x.f; i++) if(x.f%i==0){
				ans[x.f].pb(i);
				if(i*i!=x.f) ans[x.f].pb(x.f/i);
				if(ans[x.f].size()>=x.s) break;
			}
		}
		if(ans[x.f].size() < x.s) {flag=false; break;}
	}
	if(!flag) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(int i=0;i <n; i++){
			int x = ans[v[i]][ma[v[i]]-1];
			cout << x << " " << v[i]/x << endl;
			ma[v[i]]--;
		}
	}
	
	
	exit(0);
}
