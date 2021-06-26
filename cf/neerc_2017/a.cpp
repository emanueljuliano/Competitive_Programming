#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;
typedef tuple<int, int, int> T;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 4e5+10;

namespace seg {
	ll seg[4*MAX];
	int n;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = -1;
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	ll update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (l == r and l == a) return seg[p] = x;
		if (a < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, x, 2*p, l, m),
			update(a, x, 2*p+1, m+1, r));
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return -1;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
	}	
};


int main(){ _
	int n; cin >> n;
	vector<tuple<int, int, int>> ev;
	vector<tuple<int, int, int>> ent;
	for (int i=0; i<n; i++) {
		int t, x, y; cin >> t >> x >> y;
		ent.emplace_back(t, x, y);
		if (t == 1) {
			ev.push_back({x-y, 0, i});
			ev.push_back({x+y, 2, i});
		}
		else {
			ev.push_back({x, 1, i});
		}
	}
	sort(ev.begin(), ev.end());
	map<tuple<int, int, int>, int> mp;
	int pt = 0;
	for (auto u : ev) mp[u] = pt++;

	seg::n = pt;
	seg::build();
	for (int i = 0; i<ent.size(); i++){
	/*	cout << endl << "ITERAÇÂO " << i << endl;
		for (int j=0;j <pt; j++) {
			cout << j << " " << seg::query(j, j) << endl;
		}
*/
		auto [t, x, y] = ent[i];
		if (t == 1) {
			int l = mp[T(x-y, 0, i)];
			int r = mp[T(x+y, 2, i)];
			seg::update(l, r);
	//		cout << "Updatando " << l << " com " << r << endl;
		}
		else {
			int val = mp[T(x, 1, i)];
			int l = 0;
 			int ans = -2;
			while (true) {
				int pos = seg::get_left(l, val, val);
	//			cout << "get left retornou " << pos << " com a query " << val << endl;
				if (pos == -1) break;
				
				int id = get<2>(ev[pos]);
				auto [tt, xx, yy] = ent[id];
			//	cout << id << " " << tt << " " << xx << " " << yy << endl;

				if ((xx-x)*(ll)(xx-x) + (yy-y)*(ll)(yy-y) < yy*(ll)yy) {
	//				cout << "Ta dentro do circulo " << xx << " " << yy << endl;
					ans = id;
					seg::update(pos, -1);
					break;
				}
				l = pos+1;
			}
			cout << ans+1 << endl;
		}
	}

	exit(0);
}
