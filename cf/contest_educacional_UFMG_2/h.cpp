#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6+10;

namespace seg {
	pair<ii, int> seg[4 * MAX];
	int n;
	pair<ii, int> v[MAX];
	pair<ii, int> merge(pair<ii, int> a, pair<ii, int> b){
		int novos = min(a.f.f, b.f.s);
		a.f.f-=novos;
		b.f.s-=novos;
		int l = a.f.f+b.f.f;
		int r = a.f.s+b.f.s;
		int tot = a.s+b.s+novos;
		return {{l, r}, tot};
	}

	pair<ii, int> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	pair<ii, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {{0, 0}, 0};
		int m = (l+r)/2;
		return merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};


int main(){ _
	string s; cin >> s;

	seg::n = s.size();
	for(int i=0;i <seg::n; i++){
		seg::v[i] = {{s[i]=='(', s[i]==')'}, 0};
	}

	seg::build();
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r; l--, r--;
		int ans = seg::query(l, r).s;
		cout << 2*ans << endl;
	}
	
	
	
	exit(0);
}
