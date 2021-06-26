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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6;
int l[MAX], r[MAX], ord[MAX];
int n, p;

ll solve(){
	vector<ii> v;
	for(int i=0;i <n; i++){
		v.pb({l[i], r[i]});		
	}
	ii zero = {0, int(1e6)};
	auto f = [&](ii a, ii b){
		return max(0, min(a.s, b.s) - max(a.f, b.f));
	};
	auto merge = [&](ii a, ii b){
		ii ret = {max(a.f, b.f), min(a.s, b.s)};
		return ret;
	};

	bool show = true;
	for(int k=p; k<n; k++){
		vector<ii> w;
		ii mini = {INF, INF};
		ii pp = {-1, -1};
		for(int i=0;i <v.size(); i++)
			for(int j=i+1; j<v.size(); j++){
				ii val = {f(v[i], zero) + f(v[j], zero) - f(v[i], v[j]), -f(v[i], v[j])};
				if(val.s != 0 and val < mini) 
					mini = val, pp = {i, j};
			}
		if(pp.f==-1) pp = {0, 1}, show = false;
		w.pb(merge(v[pp.f], v[pp.s]));
		for(int i=0;i <v.size(); i++)
			if(i!=pp.f and i!=pp.s) w.pb(v[i]);
		v = w;
	}

	ll ans = 0;
	for(int i=0;i <p; i++){
		ans += f(zero, v[i]);
	}
	assert(show);
	return ans;
}

int main(){ _
	cin >> n >> p;
   for (int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        ord[i] = i;
    }
	ll ans = solve();
	cout << ans << endl;
	
	exit(0);
}
