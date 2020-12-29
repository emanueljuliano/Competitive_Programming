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

const int MAX = 1e5 + 10;

int seg[2 * MAX];
int n;
void build() {
	for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}
int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}
void update(int p, int x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
}

int main(){ _
	int k, m, t, cs=0; cin >> t;
	while(t--){ cout << "Testcase " << cs++ << ":" << endl;
		cin >> n >> k;
		for(int i=0;i <n; i++) cin >> seg[i+n];
		build();
		cin >> m;
		while(m--){
			char flag; int l, r; cin >> flag >> l;
			if(flag!='A') cin >> r;
			if(flag=='A') k += l;
			if(flag=='B') update(l, r);
			if(flag=='C') cout << abs(k-query(l, r)) << endl;
		}
		if(t) cout << endl;
	}
	
	exit(0);
}
