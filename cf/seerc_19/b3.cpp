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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef tuple<int, int, int, int> T;

int main(){ _
	int n, S1, S2; cin >> n >> S1 >> S2;
	vector<T> v(n);
	for(auto &[a, b, c, d] : v) cin >> a >> b >> c >> d;
	sort(v.begin(), v.end());

	ll mini = LINF;
	do{	
		int it = 0;
		int s1 = S1, s2 = S2;
		ll at = 0;
		for(; it<n; it++){
			auto [x, t, y, r] = v[it];
			s1 -= x; at += t;
			if(s1<=0){
				s2 += s1;
				it++;
				break;
			}
		}
		if(s2<=0){
			mini = min(mini, at);
			continue;
		}
		for(; it<n; it++){
			auto [x, t, y, r] = v[it];
			s2 -= y; at += r;
			if(s2<=0){
				break;
			}
		}
		if(s2<=0 and s1<=0) mini = min(mini, at);
	}while(next_permutation(v.begin(), v.end()));
	
	if(mini == LINF) cout << -1 << endl;
	else cout << mini << endl;
	
	exit(0);
}
