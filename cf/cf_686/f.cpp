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

template<typename T> struct rmq_max {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] > v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	rmq_max(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	T query(int l, int r) {
		if (r-l+1 <= b) return v[small(r, r-l+1)];
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return v[ans];
	}
};


template<typename T> struct rmq_min {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	rmq_min(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	T query(int l, int r) {
		if (r-l+1 <= b) return v[small(r, r-l+1)];
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return v[ans];
	}
};

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int, vector<int>> ap;
		vector<int> v(n);
		map<int, int> freq;
		for(auto &i : v) cin >> i, freq[i]++;
		for(int i=0;i <v.size(); i++) ap[v[i]].pb(i);
		vector<int> l, r;
		l.pb(v[0]);
		for(int i=1; i<n; i++) l.pb(max(l.back(), v[i]));
		r.pb(v[n-1]);
		for(int i=n-2; i>=0; i--) r.pb(max(r.back(), v[i]));

		set<int> val, var;
		for(auto u : l) val.insert(u);
		for(auto u : r) var.insert(u);
		
		rmq_max<int> rmax(v);
		rmq_min<int> rmin(v);

		vector<int> ans(3, -1);
		for(auto u : val) if(var.count(u) and freq[u]>=3){
			int l1, r1;	
			l1 = lower_bound(l.begin(), l.end(), u) - l.begin(); l1++;
			r1 = upper_bound(l.begin(), l.end(), u) - l.begin(); r1--;
			int l2, r2;	
			l2 = lower_bound(r.begin(), r.end(), u) - r.begin(); l2++;
			r2 = upper_bound(r.begin(), r.end(), u) - r.begin(); r2--;
			l2 = n-1-l2, r2 = n-1-r2;
			swap(l2, r2);
		
			//cout << "COUT" << endl;
			//cout << u << "  "<<  l1 << "  " << r1 << "  " << l2 << " " << r2 << endl;

			if(r1>=l2 and rmax.query(l1, r2)==u){
				for(int i=l1; i<=r2; i++) if(v[i]==u){
					ans[0] = i, ans[1]=1, ans[2]=n-ans[0]-ans[1];
					break;
				}
			}
			else if(r1<l2){
				int q = rmin.query(r1+1, l2-1);
				if(q<u) {}
				else if(q==u) 
					ans[0] = r1+1, ans[1]=l2-ans[0], ans[2]=n-ans[0]-ans[1];
				else if(q>u and v[r1]==u and r1>=l1)
					ans[0] = r1, ans[1]=l2-ans[0], ans[2]=n-ans[0]-ans[1];
				else if(q>u and v[l2]==u and r2>=l2)
					ans[0] = r1+1, ans[1]=l2+1-ans[0], ans[2]=n-ans[0]-ans[1];
			}
			if(ans[0]!=-1) break;
		}
		if(ans[0]==-1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for(auto u : ans) cout << u << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
