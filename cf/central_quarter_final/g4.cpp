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
map<pair<ii, ii>, int> mp;
vector<int> v;
int solve(int l, int r, int a, int b){
//	cout << l << " " << r << " " << a << " " << b << endl;
	pair<ii, ii> id = {{l, r}, {a, b}};
	if(mp.count(id)) return mp[id];
	set<int> st;
	for(int i=l;i <r; i++){
		int g = gcd(v[i], v[i+1]);
		if(g!=1){	
			int a1 = solve(l, i, a, v[i]/g);
			int a2 = solve(i+1, r, v[i+1]/g, b);
			st.insert(a1^a2);
		}
	}
	for(int i=0;i <v.size(); i++) if(!st.count(i)) return mp[id] = i;
	return 0;
}

int main(){ _
	int n; cin >> n;
	v.resize(n);
	for(auto &i: v) cin >> i;
	
	if(solve(0, n-1, v[0], v[n-1])) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	
	exit(0);
}
