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
	int n, k; cin >> n >> k;
	vector<int> v;
	for(int i=0;i <n; i++){
		int x; cin >> x;
		v.pb(x);
	}
	vector<ii> sz;
	vector<int> tam(k+10, 1);
	for(int i=0;i <k; i++){
		int x; cin >> x;
		tam[i+1] = x;
	}
	sort(v.begin(), v.end(), greater<>());
	vector<vector<int>> ans(n+10);
	int it1 = 0;
	int at =0;
	for(int i=0;i <n; i++){
		if(ans[0].size()<tam[v[i]]) it1=0;
		at=ans[it1].size();
		if(at < tam[v[i]]) ans[it1].pb(v[i]);
		else{
			while(at>=tam[v[i]]){
				it1++;
				at = ans[it1].size();
			}
			ans[it1].pb(v[i]);
		}
	}
	int x = 0;
	for(int i=0;i <n+5; i++) {
	
		if(ans[i].size()==0){x=i; break;}
	}
	cout << x << endl;
	for(int i=0;i <x; i++){
		cout << ans[i].size() << " " ;
		for(auto k : ans[i]) cout << k << " " ;
		cout << endl;
	}

	exit(0);
}
