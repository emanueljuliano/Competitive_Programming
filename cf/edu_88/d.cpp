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
const int MAX = 1e5+10;

int main(){ _
	int n; cin >> n;
	vector<int> v;
	map<int, vector<int>> mp;
	for(int i=0;i <n; i++) {int a; cin >> a; v.pb(a); mp[a].pb(i);}
	int ans = 0;
	for(int k=30; k>=0; k--){
		int sat = 0, id1 = 0;
		int ct = 0; 
		for(int i=0;i <n; i++){
//			if(v[i]==k) cout << "ENtrou" << endl;
//			if(v[i]==k) cout << "k= " << k << " i " << i << " sat= " << sat << endl;
			
			sat += v[i];
		//	if(k==10) cout << i << " " << sat << endl;
			if(v[i]==k){
				ct++; if(ct==1) sat -=k;
			}
			if(sat>ans and ct) ans = sat;
			if((!ct and sat<0) or (ct and sat<-k)){
				sat = 0;
				ct = 0;
			}
//			if(ct) cout << "k= " << k << " i " << i << " sat= " << sat << endl;
		}
		for(auto x : mp[k]) v[x]=-INF;
	}
	cout << ans << endl;

	exit(0);
}
