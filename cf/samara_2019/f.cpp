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


// estou matando a mim mesmo no w
// estou matando a mim mesmo nos eventos

int main(){ _
	int n; cin >> n;
	vector<ii> v, ev, ent;
	vector<pair<int, pair<ii, ii>>> w;
	for(int i=0;i <n; i++){
		int a, h; cin >> a >> h;
		v.pb({h, i}); // ordenados pela vida
		ev.pb({a, i}); // ordenados pelo dano
		ent.pb({a, h}); // entrada
	}
	sort(v.begin(), v.end());
	sort(ev.begin(), ev.end());
	sort(ent.begin(), ent.end());
	
	ll ans = 0;
	w.pb({v[0].f, {{ent[v[0].s].f, v[0].s}, {0, 0}}});
	
	for(int i=1;i <n; i++){
		int maxi = w[i-1].s.f.f;
		int id = w[i-1].s.f.s;
		int maxi2 =  w[i-1].s.s.f;
		int id2 =   w[i-1].s.s.s;
		if(ent[v[i].s].f > maxi){
			maxi2 = maxi;	
			id2 = id;
			maxi = ent[v[i].s].f;
			id = v[i].s;
		}
		else if(ent[v[i].s].f > maxi2){
			maxi2 = ent[v[i].s].f;
			id = v[i].s;
		}
		w.pb({v[i].f, {{maxi, id}, {maxi2, id2}}});
	}
	int ans1 = 0, ans2 = 1;
	for( auto IT : ev){
		int a = IT.f, ind = IT.s;
		int h = ent[ind].s;

		ii par = {a, INF};
		int up = upper_bound(v.begin(), v.end(), par) - v.begin();
		up--;
		if(up==-1) continue;

		int maxi, id, maxi2, id2;
		maxi = w[up].s.f.f;
		id = w[up].s.f.s;
		maxi2 = w[up].s.s.f;
		id2 = w[up].s.s.s;

		if(maxi > ans and id!=ind){
			ans = maxi;
			ans1 = ind;
			ans2 = id;
		}
		else if(maxi2 > ans and id2!=ind){
			ans = maxi2;
			ans1 = ind;
			ans2 = id;
		}
		if(maxi >= h){
			if(maxi+a > ans and id!=ind){
				ans = a+maxi;
				ans1 = ind;
				ans2 = id;
			}
			else if(maxi2+a > ans and id2!=ind){
				ans = a+maxi2;
				ans1 = ind;
				ans2 = id;
			}
		}
	}
	cout << ans << endl;
	cout << ans1+1 << " " << ans2+1 << endl;
	
	
	
	exit(0);
}
