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

void radix(vector<int> &p, vector<int> &c){
	int n = p.size();
	vector<int> cnt(n);
	for(auto x : c) cnt[x]++;
	vector<int> pos(n);
	pos[0] = 0;
	for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
	vector<int> p_new(n);
	for(auto x : p) p_new[pos[c[x]]++] = x;
	p = p_new;
}

int main(){ _
	string s; cin >> s;
	s += "$";
	int n = s.size();

	vector<int> p(n), c(n); // p=prefix, c=equivalence
	{
		// k = 0
		vector<pair<char, int>> a(n);
		for(int i=0; i<n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for(int i=0;i <n; i++) p[i] = a[i].s;
		c[p[0]] = 0;
		for(int i=1; i<n; i++){
			if(a[i].f != a[i-1].f) c[p[i]] = c[p[i-1]]+1;
			else c[p[i]] = c[p[i-1]];
		}
	}
	int k = 0;
	while(1<<k < n){
		for(int i=0;i <n; i++) p[i] = (p[i] - (1<<k) + n)%n;
		radix(p, c);
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		ii bef = {c[p[0]], c[(p[0] + (1<<k))%n]};
		for(int i=1; i<n; i++){
			ii at = {c[p[i]], c[(p[i] + (1<<k))%n]};
			if(at != bef) c_new[p[i]] = c_new[p[i-1]]+1;
			else c_new[p[i]] = c_new[p[i-1]];
			bef = at;
		}
		c = c_new;
		k++;
	}

	k = 0;
	vector<int> lcp(n);
	for(int i=0;i <n-1; i++){
		int pi = c[i];
		int j = p[pi-1];
		while(s[i+k]==s[j+k]) k++;
	
		lcp[pi] = k;
		k = max(k-1, 0);
	}
	ll ans = ll(n)*(n-1)/2;
	for(int i=0;i <n; i++){
		ans -= lcp[i];	
	}
	cout << ans << endl;
	
	exit(0);
}
