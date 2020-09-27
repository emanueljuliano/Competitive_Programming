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
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		int mex = 0;
		vector<int> w;
		vector<int> ans;
		int last = n-1;
		while(true){
			w = v;
			sort(w.begin(), w.end());
			vector<int>::iterator it = unique (w.begin(), w.end()); 
			w.resize( std::distance(w.begin(),it) );
			int mex = 0;
			for(int i=0;i <w.size(); i++){
				if(mex==w[i]) mex++;
				else break;
			}

			bool show = true;
			for(int i=0;i <n-1; i++) if(v[i]>v[i+1])show = false;
			if(show) break;
			if(mex==n){
				for(int i=n-1; i>=0; i--){
					if(v[i]!=i){
						v[i] = mex;
						ans.pb(i);
						break;
					}
				}
			}
			else{
				v[mex] = mex;
				ans.pb(mex);
			}
		}
		cout << ans.size() << endl;
		for(auto x : ans) cout << x+1 << " ";
		cout << endl;
	}



	exit(0);
}
