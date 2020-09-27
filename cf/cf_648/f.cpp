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
		vector<int> v(n), w(n);
		for(auto &i : v) cin >> i;
		for(auto &i : w) cin >> i;
		bool show = true;
		multiset<ii> m1, m2;
		for(int i=0;i <n; i++){
			m1.insert({v[i], v[n-i-1]});
			m2.insert({w[i], w[n-i-1]});
		}
		show = m1==m2;	
		if(show) cout << "Yes" << endl;
		else cout << "No" << endl;

	}




	exit(0);
}
