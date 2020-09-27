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


int main(){ _
	int ma=INF, mb=INF, mc=INF, ida, idb, idc;
	vector<pair<ii, ii>> v;
	vector<vector<int>> ent;
	int n; cin >> n;
	for(int i=0;i <n; i++){
		int a, b, c; cin >> a >> b >> c;
		ent.pb({a, b, c});
		v.pb({{a, i},{ b, c}});
	}
	sort(v.begin(), v.end());
	ii mini = v[0].s;
	int id = v[0].f.s;
	for(int i=1;i <n; i++){
		ii at = v[i].s;
		if(at.f < mini.f and at.s < mini.s){
			mini = at;
			id = v[i].f.s;
		}
	}
	bool ans = true;
	ii a = {ent[id][1], ent[id][2]};
	ii b = {ent[id][0], ent[id][2]};
	ii c = {ent[id][0], ent[id][1]};
	for(int i=0;i<n; i++){
		ii at = {ent[i][1], ent[i][2]};
		ii bt = {ent[i][0], ent[i][2]};
		ii ct = {ent[i][0], ent[i][1]};
		if(at.f<a.f and at.s<a.s) ans = false;
		if(bt.f<b.f and bt.s<b.s) ans = false;
		if(ct.f<c.f and ct.s<c.s) ans = false;
	}
	if(ans) cout << 1 << endl << id+1 << endl;
	else cout << 0 << endl;


	exit(0);
}
