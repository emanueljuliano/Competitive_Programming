#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 5e5+10;
const int SQ = sqrt(MAX);
int v[MAX];
vector<int>vis(MAX);

int freq[MAX];
vector<int> ans;

inline void insert(int p) {
	int o = v[p];
	freq[o]++;
	if(freq[o] == 1 and !vis[o]) ans.pb(o), vis[o]=1;
}

inline void erase(int p) {
	int o = v[p];
	freq[o]--;
	if(freq[o] == 1) ans.pb(o);
}

inline ll hilbert(int x, int y) {
	static int N = (1 << 20);
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s>0; s /= 2) {
		rx = (x & s) > 0;
		ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) {
				x = N-1 - x;
				y = N-1 - y;
			}
			swap(x, y);
		}
	}
	return d;
}

#define HILBERT false
vector<int> MO(vector<ii> &q) {
	int m = q.size();
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
#if HILBERT
	vector<ll> h(m);
	for (int i = 0; i < m; i++) h[i] = hilbert(q[i].first, q[i].second);
	sort(ord.begin(), ord.end(), [&](int l, int r) { return h[l] < h[r]; });
#else
	sort(ord.begin(), ord.end(), [&](int l, int r) {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].s > q[r].s;
		return q[l].s < q[r].s;
	});
#endif
	vector<int> ret(m);
	int l = 0, r = -1;

	for (int i : ord) {
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		while(ans.size() and freq[ans.back()]!=1)vis[ans.back()]=0, ans.pop_back();
		if(ans.size()) ret[i] = ans.back();
		else ret[i] = 0;
	}
	return ret;
}
int main(){ _
	int n; cin>>n;

	for(int i =0; i < n; i++) cin>>v[i];
	int q; cin >> q;
	vector<ii> query(q);
	for(auto &x : query) {cin >> x.f >> x.s; x.f--, x.s--;}
	vector<int> ret = MO(query);
	for(auto x : ret) cout << x << endl;


	exit(0);
}
