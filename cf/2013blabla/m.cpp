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
	int n; cin >> n;
	vector<int> v, w;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.pb(b);
	}
	int q; cin >> q;
	sort(v.begin(), v.end());
	for(int i=0; i<q; i++){
		int at; cin >> at;
		int d1 = upper_bound(v.begin(), v.end(), at) - v.begin();
		cout << d1 << endl;
	}

	
	
	exit(0);
}
