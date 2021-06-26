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

const int MAX = 3e5;
ii seg[2 * MAX];
int nn;

void build() {
	for (int i = nn - 1; i; i--) {
		if(seg[2*i].f<seg[2*i+1].f) seg[i] = seg[2*i];
		else seg[i] = seg[2*i+1];
	}
}

ii query(int a, int b) {
	ii ret = seg[a+nn];
	for(a += nn, b += nn; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) if(seg[a].f < ret.f) ret = seg[a];
		if (b % 2 == 0) if(seg[b].f < ret.f) ret = seg[b];
	}
	return ret;
}

void update(int p, ii x) {
	seg[p += nn] = x;
	while (p /= 2) {
		if(seg[2*p].f<seg[2*p+1].f) seg[p] = seg[2*p];
		else seg[p] = seg[2*p+1];
	}
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> k(n), c(m);
		for(auto &i : k) cin >> i, i--;
		for(auto &i : c) cin >> i;
		
		nn = m;
		for(int i=0;i <2*m; i++) seg[i]={INF, INF};
		for(int i=0;i <m; i++) seg[m+i]={c[i], i};
		build();

		vector<ii> v(n);
		for(int i=0;i <n; i++) v[i] = {c[k[i]], k[i]};
		sort(v.begin(), v.end(), greater<>());
	
		ll ans = 0;
		for(auto [cc, id] : v){
			ii change = query(0, id);
			//cout << id << " " cc << " " << change.f << " " << change.s << endl;
			if(change.f < cc){
				ans += change.f;
				update(change.s, {INF, change.s});
			}
			else{
				ans += cc;
			}
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
