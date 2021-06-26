#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
const int magic = 64;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j=0; i<s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) {
			match.push_back(i-j+1), j = p[j-1];
		}
	}
	return match;
}

const int MOD = 1e9+7;

int mulmod(ll a, ll b) {
	return (a*b)%MOD;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

struct str_hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;
	str_hash(string s_) : n(s_.size()), s(s_), h(n), power(n) {
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = mulmod(power[i-1], P);
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (mulmod(h[i-1], P) + s[i]) % MOD;
	}
	ll operator() (int i, int j) {
		if (!i) return h[j];
		ll ret = h[j] - mulmod(h[i-1], power[j-i+1]);
		return ret < 0 ? ret + MOD : ret;
	}
};

int str_hash::P = uniform(27, MOD-1);

map<int, pair<int, int>> mp[magic];
set<int> st[magic];

int main(){ _
	int n, m; cin >> n >> m;
	string s; cin >> s;
	
	str_hash hs(s);
	
	vector<string> ent(m);
	vector<int> hent(m);
	for (auto &i : ent) cin >> i;
	for (int i=0; i<m; i++) if (ent[i].size() <= magic) {
		str_hash h(ent[i]);
		hent[i] = h(0, ent[i].size()-1);
		st[ent[i].size()-1].insert(hent[i]);
	}

	for (int j = 0; j < min(magic, n); j++) {
		for (int i=0; i+j<n; i++) {
			ll q = hs(i, i+j);
			if (!st[j].count(q)) continue;
			if (!mp[j].count(q)) mp[j][q] = {i, 1};
			else if(mp[j][q].first < i-j) mp[j][q] = {i, mp[j][q].second+1};
		}
	}

	for (int i=0; i<m; i++) {
		string t = ent[i];

		if (t.size() <= magic) {
			cout << mp[t.size()-1][hent[i]].second << endl;
		}
		else {
			vector<int> v = matching(t, s);
			if (!v.size()) cout << 0 << endl;
			else {
				vector<int> ans = {v[0]};
				for (auto u : v) if (u - ans.back() >= t.size()) 
					ans.push_back(u);
				cout <<	ans.size() << endl;
			}
		}
	}	
	
	exit(0);
}
