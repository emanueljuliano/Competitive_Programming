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

vector<int> v;

bool ord(ii a, ii b){
	if(v[a.f] != v[b.f]) return v[a.f]>v[b.f];
	return v[a.s] > v[b.s];
}

int main(){ _
	int n; cin >> n;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	vector<ii> p;
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++){
			if(v[i]>v[j]) p.pb({i, j});
		}
	}
	sort(p.begin(), p.end(), ord);
	for(auto x : p){
		swap(v[x.f], v[x.s]);
	}
	bool show = true;
	for(int i=0;i <n-1; i++) if(v[i]>v[i+1]) show = false;
	if(!show) cout << -1 << endl;
	else{
		cout << p.size() << endl;
		for(auto x : p) cout << x.f+1 << " " << x.s+1 << endl;
	}



	exit(0);
}
