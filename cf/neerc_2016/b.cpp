#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6+10;

vector<int> get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}


namespace seg {
	int seg[4*MAX];
	vector<int> v;
	int n;

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(vector<int> v2) {
		n = v2.size(), v = v2;
		build();
	}

	// primeira posicao >= val em [a, b] (ou -1 se nao tem)
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
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	if (m > n) return cout << -1 << endl, 0;
	s += s;
	string ts = t + "$" + s;
	vector<int> vz = get_z(ts);
	vector<int> pref;
	for (int i=m+1; i<vz.size(); i++) pref.push_back(vz[i]);
	for (auto u : pref) if (u == m) return cout << n << endl, 0;
	//cout << "Pref ";
	//for (auto u : pref) cout << u << " ";
	//cout << endl;

	reverse(t.begin(), t.end());
	reverse(s.begin(), s.end());
	ts = t + "$" + s;
	vz = get_z(ts);
	vector<int> suf;
	for (int i=m+1; i<vz.size(); i++) suf.push_back(vz[i]);
	reverse(suf.begin(), suf.end());
	reverse(s.begin(), s.end());
	
	//cout << "Suf ";
	//for (auto u : suf) cout << u << " ";
	//cout << endl;


	seg::build(suf);

	int ans = -1;
	for (int i=0; i<2*n; i++) {
		int r = i + pref[i] - 1;
		int l = seg::get_left(r-n+(m-pref[i])+1, i-1, m-pref[i]);
	//	cout << i << " " << s[i] << " " << r << " " << l << endl;
		l -= m-pref[i] -1;
		if (l >= 0) ans = max(ans, r-l+1);
	}
	cout << ans << endl;

	exit(0);
}
