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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> v(1010);
int maxi;
int nq = 0;
int query(int l, int r){
	int sz = 0;
	for(int i=l; i<=r; i++) sz += v[i].size();
	cout << "? " << sz << " ";
	for(int i=l; i<=r; i++) for(auto k : v[i]) cout << k << " ";
	cout << endl;
	int ret; cin >> ret;
	return ret;
}

int bb(int l, int r){
	if(l==r) return l;
	int mid = (l+r)/2;
	int q = query(l, mid);
	if(q==maxi) r= mid;
	else l = mid+1;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n>> k;
		for(int i=0;i <=n; i++) v[i].resize(0);

		set<int> st; for(int i=1; i<=n; i++) st.insert(i);
		for(int i=0;i <k; i++){
			int sz; cin >> sz;
			for(int j=0;j<sz; j++){
				int a; cin >> a; v[i].pb(a);
				st.erase(a);
			}
		}
		cout << "? " << n << " ";
		for(int i=0;i <n; i++) cout << i+1 << " ";
		cout << endl;
		nq = 1;

		cin >> maxi;
		bool no = false;
		if(!st.empty()){
			v[k].resize(0);
			no = true;
			for(auto x : st) v[k].pb(x);
		}
		int ind = bb(0, k-1+no);
		cout << "? " << n-v[ind].size() << " ";
		for(int i=0;i <k+no; i++){
			if(i==ind) continue;
			for(auto x : v[i]) cout << x << " ";
		}
		cout << endl;
		int maxi2; cin >> maxi2;
		cout << "! ";
		for(int i=0;i <k; i++){
			if(i==ind) cout << maxi2 << " ";
			else cout << maxi << " ";
		}
		cout << endl;
		string s; cin >> s;	
	}
	
	
	
	exit(0);
}
