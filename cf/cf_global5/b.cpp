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

const int MAX = 1e5+10;
int id[MAX];
int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
}

int query(int a, int b) {
	int ret = INF;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = min(ret, seg[a]);
		if (b % 2 == 0) ret = min(ret, seg[b]);
	}
	return ret;
}

int main(){ _
	cin >> n;
	for(int i=0;i <n; i++){
		int a; cin >> a; id[a]=i;
	}
	int ans = 0;
	vector<int> v;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		seg[n+i]=id[a];
		v.pb(id[a]);
	}
	build();
	for(int i=0;i <n; i++){
		int q = query(i+1, n-1);
		if(q<v[i]) ans++;
	}
	cout << ans << endl;



	exit(0);
}
