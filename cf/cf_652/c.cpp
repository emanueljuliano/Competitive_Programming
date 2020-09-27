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
		vector<int> v(n), w(k);
		for(auto &i : v) cin >> i;
		for(auto &i : w) cin >> i;
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());
		ll ans = 0;
		for(int i=0; i<k; i++){
			ans+=v.back();
			if(w[i]==1) ans += v.back();
			v.pop_back();

		}
		vector<int> aux;
		for(int i=0;i <k; i++){
			int a = w[i]; a--; if(!a)continue;
			aux.pb(a);
		}
		if(aux.empty()){
			cout << ans << endl;
			continue;
		}
//		cout <<" ans = " << ans << endl;
		reverse(v.begin(), v.end());
		
		int at = -1;
//		for(auto x : v) cout << x<<" ";
//		cout << endl;
		for(int i=0;i <aux.size(); i++){
			at += aux[i];
//			cout << at << endl;
			ans += v[at];
		}
		cout << ans << endl;
	}	
	
	
	
	exit(0);
}
