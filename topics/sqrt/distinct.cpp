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

const int B = 1358;
ll ans=0;
int n, q;
vector<int> v, aux, to_int;
int freq[(int)2e6];
vector<pair<int, ii>> up, qu;

bool ord(pair<ii, ii> a, pair<ii, ii> b){
	ii pa = {a.f.f/B, a.f.s/B}, pb = {b.f.f/B, b.f.s/B};
	if(pa != pb) return pa < pb;
	return a.s.f < b.s.f;
}
void insert(int i){
	if(!freq[v[i]]) ans+=to_int[v[i]];
	freq[v[i]]++;
}
void erase(int i){
	freq[v[i]]--;
	if(!freq[v[i]]) ans-=to_int[v[i]];
}
void update(int t, int l, int r){
	if(up[t].f>=l and up[t].f<=r){
		erase(up[t].f);
		v[up[t].f] = up[t].s.f;
		insert(up[t].f);
	}
	else v[up[t].f] = up[t].s.f;
}
void undo(int t, int l, int r){
	if(up[t].f>=l and up[t].f<=r){
		erase(up[t].f);
		v[up[t].f] = up[t].s.s;
		insert(up[t].f);
	}
	else v[up[t].f] = up[t].s.s;
}
vector<ll> mo(){
	vector<pair<ii, ii>> ev;
	for(int i=0;i <q; i++) ev.pb({qu[i].s, {qu[i].f, i}});
	sort(ev.begin(), ev.end(), ord);
	
	vector<ll> ret(q);
	int ini = 0, end = 0, time=0;
	insert(0);
	for (auto u : ev){
		int l = u.f.f, r = u.f.s, t = u.s.f, id = u.s.s;
		while(time<t) update(time++, ini, end);	
		while(time>t) undo(--time, ini, end);
		while(end<r) insert(++end);
		while(ini>l) insert(--ini);
		while(end>r) erase(end--);
		while(ini<l) erase(ini++);

		ret[id] = ans;
	}
	return ret;
}

int main(){ _
	cin>> n;
	map<int, int> mp;
	int ptr = 0;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		if(!mp.count(a)) to_int.pb(a), mp[a]=ptr++;
		v.pb(mp[a]), aux.pb(mp[a]);
	}
	
	cin >> q;
	int at = 0;
	for(int i=0;i <q; i++){
		char c; int a, b; cin >> c >> a >> b; a--;
		if(c=='Q') qu.pb({at, {a, b-1}});
		else{
			if(!mp.count(b)) to_int.pb(b), mp[b]=ptr++;
			up.pb({a, {mp[b], aux[a]}}), aux[a]=mp[b], at++;
		}
	}
	q -= at;
	vector<ll> w = mo();
	for(auto u : w) cout << u << endl;

	exit(0);
}
