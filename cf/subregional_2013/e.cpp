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
	int n, m; cin >> n >> m;
	set<int> st;
	for(int i=1; i<=n; i++) st.insert(i);
	vector<int> ans;
	for(int i=0;i <m; i++){
		int a; cin >> a;
		st.erase(a);
	}

	if(st.empty()) cout << "*" << endl;
	else {for(auto u : st) cout << u << " "; cout << endl;}
	
	
	
	exit(0);
}
