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
		int n, k; cin >> n >> k;
		vector<int> v;
		set<int> st;
		vector<int> aux;
		for(int i=0;i <n; i++){
			int a; cin >> a; v.pb(a);
			if(!st.count(a)){
				aux.pb(a);
				st.insert(a);
			}
		}
		if(st.size()>k){
			cout << -1 << endl;
			continue;
		}
		int it1=0; int it2=0;
		vector<int> ans;
		for(int i=0;i <n; i++){
			for(int j=0;j <aux.size(); j++){
				ans.pb(aux[j]);
			}
			for(int j=aux.size(); j<k; j++){
				ans.pb(1);
			}
		}
		cout << ans.size() << endl;
		for(auto x : ans) cout << x << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
