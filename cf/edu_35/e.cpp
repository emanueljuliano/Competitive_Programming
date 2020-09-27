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

const int MAX = 2e5+10;
int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}

int seg2[2 * MAX];

void build2() {
	for (int i = n - 1; i; i--) seg2[i] = min(seg2[2*i], seg2[2*i+1]);
}

int query2(int a, int b) {
	int ret = INF;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = min(ret, seg2[a]);
		if (b % 2 == 0) ret = min(ret, seg2[b]);
	}
	return ret;
}


int bb(int l, int r, int at){
	if(l==r) return l;
	int m = (l+r)/2;
	if(query(l, m) < at) l = m+1;
	else r = m;
	return bb(l, r, at);
}

int main(){ _
	int k; cin >> n >> k;	
	vector<int> v;
	int maxi=0;
	set<int> st;
	for(int i=0;i <k; i++){
		int a; cin >> a; v.pb(a);
		st.insert(a);
		seg[n+i]=a;
		seg2[n+i]=a;
		maxi = max(maxi, a);
	}
	vector<int> w = v;
	sort(w.begin(), w.end());
	int mini = 0;
	for(int i=0; i<k; i++){
		for(int j=w[i]; j>mini; j--){
			if(!st.count(j)){
				v.pb(j);
				seg[n+v.size()-1]=j;
				seg2[n+v.size()-1]=j;
			}
		}
		mini = w[i];
	}
	for(int i=n; i>maxi; i--){
		if(!st.count(i)){
			v.pb(i);
			seg[n+v.size()-1]=i;
			seg2[n+v.size()-1]=i;
		}
	}
	
//	for(auto x : v) cout << x << " ";
//	cout << endl;
	build();
	build2();
	bool show = true;
	for(int i=0;i <k; i++){
		int at = v[i];
		int prox = bb(i+1, n-1, at);
		if(v[prox]<at) continue;
		if(query2(prox, n-1)<at) show = false;
	//	cout << prox << " " << query2(prox, k-1) << endl;
	}
	if(show){
		for(auto w : v) cout << w << " " ;
		cout << endl;
	}
	else cout << -1 << endl;


	exit(0);
}
