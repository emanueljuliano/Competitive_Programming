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
		set<ii> st;
		int n, m, k; cin >> n >> m >> k;
		vector v(m, vector<int> (26));
		string a, b; cin >> a >> b;
		for(int i=0;i <n-k+1; i++){
			st.insert({a[i]-'a', a[i+k-1]-'a'});
		}
	//	for(auto c : st) cout << c.f << " " << c.s << endl;;
	//	cout << endl;
		v[0][b[0]-'a']++;
		for(int i=1;i <m; i++){
			for(int j=0; j<26; j++) v[i][j] = v[i-1][j];
			v[i][b[i]-'a']++;
		}	
		ll ans = 0;
		for(int i=0;i <m; i++){
			for(int j=0; j<26; j++){
				if(i==0) ans += (ll)(v[m-1][j]) * st.count({b[i]-'a', j});
				else ans += (ll)(v[m-1][j]-v[i-1][j]) * st.count({b[i]-'a', j});
			}
		}
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
