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

vector<int> calc(vector<int> w){
	int m = w.size();
	vector<int> ret;
	for(int i=0; i<(1<<m); i++){
		int at = 0;
		for(int j=0; j<m; j++) if(i&(1<<j)){
			at+=w[j];
		}
		ret.pb(at);
	}
	return ret;
}


int main(){ _
	int n, a, b; cin >> n >> a >> b;
	vector<int> v;
	for(int i=0;i <n; i++){
		int x; cin >> x; v.pb(x);
	}
	ll ans = 0;
	vector<int> w; for(int i=0;i <n/2; i++) w.pb(v[i]);
	vector<int> v1 = calc(w);
	w.clear();
	for(int i=n/2; i<n; i++) w.pb(v[i]);
	vector<int> v2 = calc(w);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	//for(auto k : v1) cout << k << " ";
	//cout << endl;
	//for(auto k : v2) cout << k << " ";
	//cout << endl;
	for(auto x : v1){
		// x + algo <= b
		// algo  <= b-x
		// x + algo >= a
		ans += upper_bound(v2.begin(), v2.end(), b-x) - upper_bound(v2.begin(), v2.end(), a-1-x);
	}
	cout << ans << endl;


	exit(0);
}
