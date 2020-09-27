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

void count_sort(vector<int> &p, vector<int> &c){
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
		count_sort(p, c);
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


	int t; cin >> t;
	while(t--){
		string a; cin >> a;

		bool has;
		int l = 0, r = n-1, pos, ans1, ans2;
	//	cout << "WHILE" << endl;
		while(l<r){
			int m = (l+r+1)/2;
			if(l==m) break;

			pos = p[m];
			has = true;
			for(int i=0; i<a.size(); i++) if(s[pos+i]!=a[i]){
				has = false; 
				if(s[pos+i]<a[i]) l = m; else r = m-1;
				break;
			}
			if(has) r = m-1;
		}
		ans1 = l;
		
		l = 0, r = n;
		while(l<r){
			int m = (l+r)/2;
			if(r==m) break;

			pos = p[m];
			has = true;
			for(int i=0; i<a.size(); i++) if(s[pos+i]!=a[i]){
				has = false; 
				if(s[pos+i]<a[i]) l = m+1; else r = m;
				break;
			}
			if(has) l = m+1;
		}
		ans2 = r;
		
	//	cout << ans1 << " "  << s.substr(p[ans1], n-p[ans1]) << endl;
	//	cout << ans2 << " "  << s.substr(p[ans2], n-p[ans2]) << endl;
		cout << ans2 - ans1 -1 << endl;
	}

	exit(0);
}
