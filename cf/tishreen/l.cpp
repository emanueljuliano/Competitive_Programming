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
		vector M(n, vector<int> (n));
		for(auto &i : M) for(auto &j: i) cin >> j;

		auto f = [&](){
			ll ans = 0;
			for(int i=0;i <n; i++){
				vector<int> maxi(n, -INF);
				for(int j=i; j<n; j++){
					vector<ii> st;
					ll sum=0;
					for(int r=0; r<n; r++){
						maxi[r] = max(maxi[r], M[r][j]);
						int at = maxi[r];
						int cnt = 1;
						while(st.size() and st.back().f<at){
							cnt+=st.back().s;
							sum -= st.back().f*st.back().s;
							st.pop_back();
						}
						st.pb({at, cnt});
						sum += at*cnt;
						ans += sum;
					}
				}
			}
			return ans;
		};
		ll ans = f();
		for(int i=0; i<n; i++) for(int j=0; j<n; j++) M[i][j] = -M[i][j];
		ans += f();
		cout << ans << endl;
	}


	exit(0);
}

