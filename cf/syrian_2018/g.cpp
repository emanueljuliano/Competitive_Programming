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
	freopen("topo.in", "r", stdin);	
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		
		vector<int> cic;
		for(int i=0;i <n; i++) if(b[i]>=1) cic.pb(i);
		
		if(cic.size()==1){
			cout << -1 << endl;
			continue;
		}

		vector<ii> ans;
		for(int i=0;i <int(cic.size()); i++) 
			ans.pb({cic[i], cic[(i+1)%cic.size()]});
		
		bool show = true;
		for(int i=0;i <cic.size(); i++){
			if(b[cic[i]] >= cic.size()) show = false;
			else{
				for(int j=1; j<b[cic[i]]; j++)
					ans.pb({cic[(i+j)%cic.size()], cic[i]});
			}
		}
		vector<ii> add_pendant, nxt_pendant;
		vector<int> pendant;
		for(int i=0;i <n; i++) if(a[i]==0) pendant.pb(i);
		for(int i=0;i <n; i++) if(a[i]!=0 and b[i]==0) nxt_pendant.pb({a[i], i});
		sort(nxt_pendant.begin(), nxt_pendant.end());
		for(auto [i, j] : nxt_pendant) {
			if(i>pendant.size()) show = false;
			else {
				for(int k=0; k<i; k++) ans.pb({pendant[k], j});
				pendant.pb(j);
				a[j] = 0;
			}
		}
		for(int i=0;i <n; i++) add_pendant.pb({a[i]-b[i], i});

		sort(add_pendant.begin(), add_pendant.end(), greater<>());
		if(add_pendant[0].f > pendant.size()) show = false;
		else{
			int sz = add_pendant[0].f;
			for(int j=0;j <sz; j++){
				for(int i=0;i <n; i++){
					if(!add_pendant[i].f) break;
					ans.pb({pendant[j], add_pendant[i].s});
					add_pendant[i].f--;
				}
			}
		}
		if(!show) cout << -1 << endl;
		else{
			cout << ans.size() << endl;
			for(auto [i, j] : ans) cout << i+1 << " " << j+1 << endl;
		}
	}
	
	
	exit(0);
}
