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

const int MAX = 1010;
vector<int> ans(MAX);

void solve(vector<int> v, vector<int> w){
	if(!v.size()) return;
	if(v.size()==1) {ans[v[0]] = w[0]; return;}

	int at = v[1];
	vector<int> vl, vr, wl, wr;

	for(auto u : w){
		cout << "? " << at << " " << u << endl;
		char c; cin >> c;
		if(c=='>') wl.pb(u);
		else if(c=='<') wr.pb(u);
		else ans[at] = u;
	}
	for(auto u : v){
		cout << "? " << u << " " << ans[at] << endl;
		char c; cin >> c;
		if(c=='<') vl.pb(u);
		else if(c=='>') vr.pb(u);
	}
	/*
	cout << "left" << endl;
	for(auto u : vl) cout << u << " ";
	cout << endl;
	for(auto u : wl) cout << u << " ";
	cout << endl;
	cout << "right" << endl;
	for(auto u : vr) cout << u << " ";
	cout << endl;
	for(auto u : wr) cout << u << " ";
	cout << endl << endl;
	*/

	solve(vl, wl);
	solve(vr, wr);
}

int main(){ _
	int n; cin >> n;

	vector<int> v, w;
	for(int i=1;i <=n; i++) v.pb(i);
	w = v;
	solve(v, w);
	

	cout << "! ";
	for(int i=1; i<=n; i++) cout << ans[i] << " ";
	cout << endl;

	exit(0);
}
