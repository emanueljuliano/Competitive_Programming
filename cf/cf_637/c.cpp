#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
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
		int n;
		cin >> n;
		vector<int> v, w(n+2, 0);
		v.pb(0);
		for(int i=1;i <=n; i++){
			int a; cin >> a;
			v.pb(a);
			w[a]=i;
		}
		int f = n;
		bool flag = true;
		vector<int> ans(n+2, 0);
		for(int i=1;i<=n; i++){
		//	cout << i<< endl;
		//	if(ans[i]!=0) continue;
			if(ans[w[i]] != 0) break;
			if(w[i]==f){
				ans[w[i]] = i, f--;
				continue;
			}
			else{
		//		cout << "entrou " << i << endl;
				int it = w[i];
				int at = i;
				while(it<=f){ ans[it] = at; at++; it++;}
				
				f = w[i]-1;
				i = at-1;
		//		for(auto k : ans) cout << k << " ";
		//		cout << endl;
		//		cout << "saiu " << i << endl;
			}
		}
	//	for(auto k : ans) cout << k << " " ;
	//	cout << endl;
		for(int i=1; i<=n; i++){
			if(ans[i] != v[i]) flag = false;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}
	
	
	
	exit(0);
}
