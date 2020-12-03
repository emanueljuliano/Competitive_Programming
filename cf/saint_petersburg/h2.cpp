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
struct DATA{
	bool rev = false;
	int a=0, b=0, ca, cb;
	int l=-1, r=-1;
};

vector<DATA> id;
vector<int> to_print;
void print(DATA x){
	//cout << "a " << x.a << " " << x.ca << " " << x.l << endl;
	//cout << "b " << x.b << " " << x.cb << " " << x.r << endl;
	if(x.l==-1){
		if(!x.rev) to_print.pb(x.a), to_print.pb(x.b);
		else to_print.pb(x.b), to_print.pb(x.a);
	}
	else{
		if(!x.rev) print(id[x.l]), print(id[x.r]);
		else{
			id[x.r].rev = true, print(id[x.r]);
			id[x.l].rev = true, print(id[x.l]);
		}
	}
}

void resp(vector<DATA> ans){
	int ca=ans[0].ca, cb=ans[0].cb;
	print(ans[0]);
	for(int i=1; i<ans.size(); i++){
		if(ans[i].ca == cb) ans[i].rev=true;
		else if(ans[i].cb==ca) ans[i].rev = true;
		print(ans[i]);
		if(!ans[i].rev) cb = ans[i].cb;
		else cb = ans[i].ca;
	}
	cout << to_print.size()/2 << endl;
	for(auto u : to_print) cout << u << " ";
	cout << endl;
	exit(0);
}

bool ord(DATA a, DATA b){
	return a.ca < b.ca;
}

int main(){ _
	int n; cin >> n;
	int sz = 2*n+2;
	vector<int> f(sz); fa.resize(sz), c.resize(sz);
	vector<DATA> v, w;

	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		DATA x, y;
		x.a = 2*i+1, x.ca = a, x.b=2*i+2, x.cb = b;
		f[a]++, f[b]++;
		if(a==b) w.pb(x), fa[a]++, fa[b]++;
		else v.pb(x);
	}
	
	int mx = 0, ma=0;
	for(int i=1;i <sz; i++) if(f[i] > mx) mx = f[i], ma = i; 
	if(mx==2*n) return cout << 1 << endl << w[0].a << " " << w[0].b << endl, 0;
	
	if(mx > n){
		int nn = n;
		vector<DATA> nw;
		for(auto x : w) {
			if(x.ca==ma and f[ma]>nn) nn--, f[ma]-=2, fa[ma]-=2;
			else nw.pb(x);
		}
		w = nw;
	}
	if(w.empty()) resp(v);
	
	mx = fa[w[0].ca], ma=w[0].ca;
	for(int i=1;i <sz; i++) if(fa[i] > mx) mx = fa[i], ma = i; 
	
	vector<DATA> ans;
	if(mx > w.size()){
		vector<DATA> dif_a, eq_a;
		for(auto x : w){
			if(x.ca==ma) eq_a.pb(x);
			else dif_a.pb(x);
		}
		for(int i=0; i<dif_a.size(); i++){
			DATA x = eq_a[i], y = dif_a[i];
			id.pb(x), id.pb(y);
			DATA z; z.a=x.a, z.ca = x.ca, z.b=y.b, z.cb = y.cb, z.l=id.size()-2, z.r=id.size()-1;
			ans.pb(z);
		}
		int it = dif_a.size();
		for(auto x : v){
			if(it<eq_a.size() and x.ca!=ma and x.cb!=ma){
				DATA y = eq_a[it++], z;
				id.pb(x), id.pb(y);
				z.a = x.a, z.ca = x.ca, z.b = y.b, z.cb = y.cb, z.l=id.size()-2, z.r=id.size()-1;
				ans.pb(z);
			}
			else ans.pb(x);
		}
		resp(ans);
	}
	else{
		sort(w.begin(), w.end(), ord);
		if(w.size()%2){
			
			DATA out;
			vector<int> inter(sz);
			if(v.size()) inter[v[0].ca] = true, inter[v[0].cb] = true;
			for(auto x : w) if(!inter[x.ca]) out = x;
			vector<DATA> nw;
			for(auto x : w) if(x.a!=out.a) nw.pb(x);
			w = nw;
			for(int i=0; i<w.size()/2; i++){
				DATA x = w[i], y = w[i+w.size()/2], z;
				id.pb(x), id.pb(y);
				z.a = x.a, z.ca = x.ca, z.b = y.b, z.cb = y.cb, z.l=id.size()-2, z.r=id.size()-1;
				ans.pb(z);
			}	
			if(!v.size()) {
				DATA y, z;
				for(auto x : ans) if(x.ca!=out.ca and x.cb!=out.ca) y=x;
				vector<DATA> nans;
				for(auto x : ans) {
					if(x.a != y.a) nans.pb(x);
					else{
						y = out;
						id.pb(x), id.pb(y);
						z.a=x.a, z.ca=x.ca, z.b=y.b, z.cb=y.cb, z.l=id.size()-2, z.r=id.size()-1;
						nans.pb(z);
					}
				}
				resp(nans);
			}
			bool used_out = false;
			for(auto x : v){
				if(!used_out and x.ca!=out.ca and x.cb!=out.cb){
					DATA y = out, z;
					id.pb(x), id.pb(y);
					z.a=x.a, z.ca=x.ca, z.b=y.b, z.cb=y.cb, z.l=id.size()-2, z.r=id.size()-1;
					ans.pb(z);
					used_out = true;
				}
				else ans.pb(x);
			}
			resp(ans);
		}
		else{
			for(int i=0; i<w.size()/2; i++){
				DATA x = w[i], y = w[i+w.size()/2], z;
				id.pb(x), id.pb(y);
				z.a = x.a, z.ca = x.ca, z.b = y.b, z.cb = y.cb, z.l=id.size()-2, z.r=id.size()-1;
				ans.pb(z);
			}
			for(auto x : v) ans.pb(x);
			resp(ans);
		}
	}
	exit(0);
}
