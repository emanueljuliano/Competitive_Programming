#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 1e10;

multiset<ll> mst;
set<pair<ll, ll>> st;
int y_min=INF, x_min=INF;
bool corner = false;

ll query(ll z){
	if(x_min!=0 or y_min!=0) return LINF;
	if(corner) return 0;
	if(!mst.size()) return LINF;
	return (*mst.rbegin())+z;
}

void rem(pair<ll, ll> p, int t){
	auto nxt = st.find(p);
	auto [x1, y1] = p;
	auto aux = nxt;
	aux++;
	if(aux != st.end()) {
		auto [x2, y2] = *aux;
		mst.erase(mst.find(x2-1 + y1-1));
	}
	if(!t){
		aux = nxt;
		if(aux != st.begin()){
			aux--;
			auto [x2, y2] = *aux;
			mst.erase(mst.find(x1-1 + y2-1));
		}
	}
	st.erase({x1, y1});
}

void add(ll x, ll y){
	int t = 0;
	//cout << st.size() << endl;
	//for(auto [a, b] : st) cout << a << " " << b << endl;
	while(true){
		if(!st.size()){
			st.insert({x, y});
			return;
		}

		auto it = st.lower_bound({x, -1});
		if(!t and it!=st.end() and it->f == x){
			if(it->s<=y) return;
			else{
				rem(*it, t++);
				continue;
			}
		}
		if(it!=st.end()){
			auto nxt = it;
			if(nxt->s >=y) {
				rem(*nxt, t++); // é dominado
				continue;
			}
		}

		if(it != st.begin()){
			auto prev = it; prev--;
			if(prev->s <=y) return; // domina
		}
		break;
	}
	
	if(t==0){ // void adicionar (x, y) e não removi adjacencia
		auto it = st.lower_bound({x, -1});
		if(it!=st.end() and it!=st.begin()){
			auto prev = it; prev--;
			mst.erase(mst.find(it->f-1+prev->s-1));
		}
	}
	auto it = st.lower_bound({x, -1});
	if(it != st.end()) mst.insert(it->f-1+y-1);
	if(it != st.begin()) it--, mst.insert(x-1+it->s-1);
	
	st.insert({x, y});
}

int main(){ _
	int n; cin >> n;

	vector<tuple<int, int, int>> v(n);
	for(auto &[x, y, z] : v) cin >> x >> y >> z;
	sort(v.begin(), v.end(), [](auto a, auto b){
		return get<2>(a) < get<2>(b);
	});

	int last = get<2>(v[0]);
	ll ans = 0;
	for(auto [x, y, z] : v){
		if(z != last){
			ans = max(ans, query(z-1));
		}
		x_min = min(x_min, x);
		y_min = min(y_min, y);
		if(x==0 and y==0) corner = true;
		add(x, y);
	}	
	ans = max(ans, query(LINF));

	if(ans >= LINF) cout << "Infinity" << endl;
	else cout << ans << endl;


	exit(0);
}
