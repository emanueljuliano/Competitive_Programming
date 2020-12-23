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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;

	vector<ii> v;
	int tot = 0;
	for(int i=0;i <2*n; i++){
		char a; cin >> a;
		int b;
		if(a=='+') v.pb({0, tot++});
		else cin >> b, v.pb({1, b});
	}

	set<int> st;
	vector<int> ans(n);
	for(int i=2*n-1; i+1; i--){
		auto [a, x] = v[i];
		//cout << a << " " << x << endl;
		if(a==0 and st.empty()) return cout << "NO" << endl, 0;
		if(a==0){
			int y = *st.begin(); st.erase(y);
			ans[x] = y;
		}
		if(a==1 and st.size() and (*st.begin())<x) return cout << "NO" << endl, 0;
		if(a==1) st.insert(x);
		
	}
	cout << "YES" << endl;
	for(auto u : ans) cout << u << " ";
	cout << endl;
	
	
	exit(0);
}
