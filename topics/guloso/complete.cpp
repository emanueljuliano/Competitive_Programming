#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define s second
#define f first

typedef pair<int, int> ii;
typedef long long ll;

bool cmp(ii a, ii b){
	if(a.f+a.s != b.f + b.s) return a.f+a.s > b.f + b.s;
	return a > b;
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<ii> v, w, z;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		if(b>=0) v.pb({a, b});
		else w.pb({max(a, -b), b});
	}

	sort(v.begin(), v.end());
	sort(w.begin(), w.end(), cmp);

	for(auto [a, b] : v){
		if(a>m) return cout << "NO" << endl, 0;
		m += b;
	}
	for(auto [a, b] : w){
		if(a>m) return cout << "NO" << endl, 0;
		m += b;
	}

	if(m<0) cout << "NO" << endl;
	else cout << "YES" << endl;

	exit(0);
}
