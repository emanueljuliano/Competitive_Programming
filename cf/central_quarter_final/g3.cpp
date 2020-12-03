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
int n;
int solve(vector<int> v){
	set<int> st;
	for(int i=0;i <v.size()-1; i++){
		int g = gcd(v[i], v[i+1]);
		if(g!=1){	
			vector<int> w;
			for(int j=0; j<=i; j++) w.pb(v[j]);
			w[i]/=g;
			int a1 = solve(w);
			w.clear();
			for(int j=i+1; j<v.size(); j++) w.pb(v[j]);
			w[0]/=g;
			int a2 = solve(w);
			st.insert(a1^a2);
		}
	}
	for(int i=0;i <n; i++) if(!st.count(i)) return i;
	return 0;
}

int main(){ _
	cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	
	if(solve(v)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	
	exit(0);
}
