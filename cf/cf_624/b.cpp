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
		int n, m; cin >> n >> m;
		vector<int> v, p(110, 0);
		int a;
		bool ans = true;
		
		for(int i=0; i<n; i++) {cin >> a;v.pb(a);}
		for(int i=0; i<m; i++) {cin >> a; p[a-1]=1;}
		vector<int> w = v;
		sort(w.begin(), w.end());
		for(int i=0; i<n; i++){
			int x = 0;
			for(int j=0; j<n; j++){
				if(v[j]==w[i]){
					v[j] = -1;
					for(int k=min(i, j); k<max(i, j); k++){
						x+= p[k];
					}
					if(x<abs(i-j)) ans = false;
					break;
				}
			}	
		}
		if(ans) cout << "YES" << endl;
		else cout <<"NO" << endl;
	}
	
	
	
	exit(0);
}
