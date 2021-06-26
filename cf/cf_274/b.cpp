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

int main(){ _
	int n, k; cin >> n >> k;

	vector<int> v(n);
	for(auto &i : v) cin >> i;
		
	set<ii> st;
	for(int i=0;i <v.size(); i++) st.insert({v[i], i});

	vector<ii> ans;

	int m = INF;
	for(int i=0;i <k; i++){
		ii lo = *st.begin();
		ii hi = *st.rbegin();
		if(lo.f==hi.f) break;	
		
		st.erase(lo);
		st.erase(hi);
		ans.pb({hi.s, lo.s});
		v[lo.s]++;
		v[hi.s]--;
		st.insert({v[lo.s], lo.s});
		st.insert({v[hi.s], hi.s});
	}
	
	ii lo = *st.begin();
	ii hi = *st.rbegin();
	m = hi.f - lo.f;
	
	cout << m << " "<< ans.size() << endl;
	for(auto [a, b] : ans) cout << a+1 << " " << b+1 << endl;
	
	
	exit(0);
}
