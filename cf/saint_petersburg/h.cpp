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

vector<int> c, fa;

void resp(vector<ii> ans, int ind=0){
	int ca =c[ans[0].f], cb = c[ans[0].s];
	cout << ans.size() << endl;
	cout << ans[0].f << " " << ans[0].s << " ";
	for(int i=1; i<ans.size(); i++){
		if(c[ans[i].s] == ca) swap(ans[i].f, ans[i].s);
		if(c[ans[i].f] == cb) swap(ans[i].f, ans[i].s);
		assert(cb != c[ans[i].f] or 
		!(ind==2));
		cb = c[ans[i].s];
		cout << ans[i].f << " " << ans[i].s << " ";
	}
	cout << endl;
	assert(cb != ca or ind!=2);
	//cout << 1 << endl;	
	exit(0);
};
bool ord(ii a, ii b){
	return c[a.f] < c[b.f];
}
int sz;
int main(){ _
	int n; cin >> n;
	sz = 4*n+10;
	vector<int> f(sz); fa.resize(sz), c.resize(sz);
	vector<ii> v, w;

	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		c[2*i+1] = a, c[2*i+2] = b, f[a]++, f[b]++;
		if(a==b) w.pb({2*i+1, 2*i+2}), fa[a]++, fa[b]++;
		else v.pb({2*i+1, 2*i+2});
	}
	
	int mx = 0, ma=0, nn=n;
	for(int i=1;i <sz; i++) if(f[i] > mx) mx = f[i], ma = i; 
	if(mx==2*n) return cout << 1 << endl << w[0].f << " " << w[0].s << endl, 0;
	//if(mx==2*n) return cout << 1 << endl, 0;
	if(mx > n){
		vector<ii> nw;
		for(auto [a, b] : w) {
			if(c[a]==ma and f[ma]>nn) nn--, f[ma]-=2, fa[ma]-=2;
			else nw.pb({a, b});
		}
		w = nw;
	}
	if(w.empty()) resp(v);
	
	sort(w.begin(), w.end(), ord);
	mx = fa[w[0].f], ma=w[0].f;
	for(int i=1;i <sz; i++) if(fa[i] > mx) mx = fa[i], ma = i; 
	
	vector<ii> ans;
	if(mx > w.size()){
		vector<ii> dif_a, eq_a;
		for(auto [a, b] : w){
			if(c[a]==ma) eq_a.pb({a, b});
			else dif_a.pb({a, b});
		}
		for(int i=0; i<dif_a.size(); i++){
			ans.pb({eq_a[i].f, eq_a[i].s});
			ans.pb({dif_a[i].f, dif_a[i].s});
		}
		int it = dif_a.size();
		vector<ii> nv;
		for(auto u : v){
			if(it<eq_a.size() and c[u.f]!=ma and c[u.s]!=ma) ans.pb(eq_a[it++]), ans.pb(u);
			else nv.pb(u);
		}
		for(auto u : nv) ans.pb(u);
		resp(ans, 1);
	}
	else{
		sort(w.begin(), w.end(), ord);
		if(w.size()%2){
			ii out={0, 0};
			vector<int> inter(sz);
			if(v.size()) inter[c[v[0].f]] = true, inter[c[v[0].s]] = true;
			for(auto u : w) if(!inter[c[u.f]]) {out = u;}
			vector<ii> nw;
			for(auto u : w) if(u!=out) nw.pb(u);
			w = nw;
			int ca = 0, cb=0;
			for(int i=0; i<w.size()/2; i++){
				if(!ca) ca = c[w[i].f],  ans.pb(w[i]), ans.pb(w[i+w.size()/2]);
				else if(c[w[i].f]==cb) ans.pb(w[i+w.size()/2]), ans.pb(w[i]);
				else ans.pb(w[i]), ans.pb(w[i+w.size()/2]);
				cb = c[ans.back().f];
			}	
			if(!v.size()) ans.pb(out);
			bool used_out = false;
			vector<ii> nv;
			for(auto u : v){
				if(!used_out and c[u.f]!=c[out.f] and c[u.s]!=c[out.s]){
					if(ans.size() and c[ans.back().s]==c[out.f]) ans.pb(u), ans.pb(out);
					else ans.pb(out), ans.pb(u);
					used_out = true;
				}
				else nv.pb(u);
			}
			for(auto u : nv) ans.pb(u);
			resp(ans, 2);
		}
		else{
			int ca = 0, cb=0;
			for(int i=0; i<w.size()/2; i++){
				if(!ca) ca = c[w[i].f], ans.pb(w[i]), ans.pb(w[i+w.size()/2]);
				else if(c[w[i].f]==cb) ans.pb(w[i+w.size()/2]), ans.pb(w[i]);
				else ans.pb(w[i]), ans.pb(w[i+w.size()/2]);
				cb = c[ans.back().f];
			}
			for(auto u : v) ans.pb(u);
			resp(ans, 3);
		}
	}
	exit(0);
}
