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

vector<int> v;
vector<ii> ans;
int t;
void solve(int l, int r, int k, int rev){
	if(ans.size()>=t) return;
	if(!k) return;
//	cout << l << " " << r << " " << k << " " << rev << endl;
	if(!rev){
		for(int i=l; i<=r-k; i++){
			solve(i+1, r, k-1, rev);
			if(v[i+1]!=1){
				v[i]=0, v[i+1]=1, ans.pb({i, i+1}), rev=true;
			}
			else{
				v[i]=0, v[i+k]=1, ans.pb({i, i+k}), rev = false;
			}
		}
	}
	else{
		for(int i=r; i>=l+k; i--){
			solve(l, i-1, k-1, rev);
			if(v[i-1]!=1) v[i]=0, v[i-1]=1, ans.pb({i, i-1}), rev=false;
			else v[i]=0, v[i-k]=1, ans.pb({i, i-k}), rev = true;
		}
	}
}

int main(){ _
	int n, k;
	cin >> n >> k >> t;

	v.resize(n+10);
	for(int i=0;i <k; i++) v[i] = 1;	
	solve(0, n-1, k, 0);

	if(ans.size()+1<t) return cout << 0 << endl, 0;
	set<int> st;
	for(int i=0;i <k; i++) st.insert(i);
	
	cout << min(t, (int)ans.size()+1) << endl;
	for(int i=1; i<=k; i++) cout << i << " ";
	cout << endl;
	for(int i=0; i<t-1; i++){
		int a=ans[i].f, b=ans[i].s;
		if(st.count(a)) st.erase(a), st.insert(b);
		else st.erase(b), st.insert(a);
		for(auto u : st) cout << u+1 << " ";
		cout << endl;
	}

	exit(0);
}
