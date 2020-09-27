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
const int MAX = 2e5 + 10;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin>> n;
		vector<int> p(n), c(n);
		for(int i=0; i<n; i++) {cin >> p[i]; p[i]--;}
		for(int i=0; i<n; i++) {cin >> c[i]; c[i]--;}
		int ans = n;

		vector<int> visto(n, 0);
		for(int i=0; i<n; i++){
			if(visto[i]) continue;
			visto[i]=1;
			int at = p[i];
			vector<int> cic;
			vector<int> cores;
			cic.pb(i);
			cores.pb(c[i]);
			while(at!=i){
				visto[at] = 1;
				cic.pb(at);
				cores.pb(c[at]);
				at = p[at];
			}
			ans = min(ans, (int)cic.size());
			if(ans==1) break;
			bool flag = true;
			for(int j=0; j<cores.size(); j++) if(cores[j]!=cores[0]) flag = false;
			if(flag) ans = 1;
			for(int k=2; k<cic.size(); k++) if(cic.size()%k==0){
				for(int j=0; j<k; j++){
					bool flag = true;
					int at = (j+k)%cic.size();
					while(at!=j){
						if(c[cic[at]]!=c[cic[j]]) flag = false;
						at = (at+k)%cic.size();
					}
					if(flag){ ans = min(ans, k); break;}
				}
			}
		}
		cout << ans << endl;
	}
	
	
	exit(0);
}
