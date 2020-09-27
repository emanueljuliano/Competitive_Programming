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
	int out = 0;
	while(out<t){
		out++;
		int n, k; cin >> n >> k;
		set<pair<ii, ii>> st;
		vector<int> v;
		for(int i=0; i<n; i++){
			int a; cin >> a;
			v.pb(a);
		}
		for(int i=1; i<n; i++){
			int a = v[i] - v[i-1];
			st.insert({{a, i}, {a, 1}});
		}	
		for(int i=0; i<k; i++){
			pair<ii, ii> aux = *st.rbegin();
			st.erase(*st.rbegin());
			int j = aux.f.s;
			int ori = aux.s.f;
			int div = aux.s.s+1;
			int at = (ori-1+div)/div;
			st.insert({{at, j}, {ori, div}});
		}
		int ans = (*st.rbegin()).f.f;
		cout << "Case #" << out << ": " << ans << endl;
	}
	
	
	exit(0);
}
