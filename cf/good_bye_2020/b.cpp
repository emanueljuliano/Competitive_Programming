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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end());
		set<int> st;
		for(auto u : v){
			if(!st.count(u)) st.insert(u);
			else st.insert(u+1);
		}
		cout << st.size() << endl;
	}
	
	
	
	exit(0);
}
