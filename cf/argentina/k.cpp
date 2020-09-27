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
int n;
const int MAX = 1e5+10;
struct seg_t{
	int seg[4*MAX], lazy[4*MAX];
	void prop(int p, int l, int r) {
		if (lazy[p]==-1) {
			return;
		}
		int m = (l+r)/2;
		seg[2*p] = lazy[p]*(m-l+1);
		seg[2*p+1] = lazy[p]*(r-(m+1)+1);
		lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] = x*(r-l+1);
			lazy[p] = x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

int main(){ _
	vector<seg_t> seg(26);
	int q; cin >> n >> q;
	string s; cin >> s;

	for(int i=0;i <26; i++){
		memset(seg[i].lazy, -1, sizeof seg[i].lazy);
		for(int j=0; j<s.size(); j++) if(int(s[j]-'a')==i) 
			seg[i].update(j, j, 1);
	}
	

	while(q--){
		int l, r, k; cin >> l >> r >> k; l--, r--;
		vector<int> v(26);
		for(int i=0;i<26; i++) 
			v[i] = seg[i].query(l, r), seg[i].update(l, r, 0);
		if(k){ //non-decreasing
			for(int i=0;i <26; i++) if(v[i]){
				seg[i].update(l, l+v[i]-1, 1);
				l += v[i];
			}
		}
		else{
			for(int i=25;i+1; i--) if(v[i]){
				seg[i].update(l, l+v[i]-1, 1);
				l += v[i];
			}
		}
	}

	for(int i=0;i <n; i++) for(int j=0; j<26; j++) 
		if(seg[j].query(i, i)) cout << char(j+'a');
	cout << endl;

	exit(0);
}
