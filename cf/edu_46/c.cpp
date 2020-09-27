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
	int n; cin >> n;
	vector<pair < pair<ll, bool>, int > > ev;
	
	map<ll, int> xini;
	for(int i=0;i <n; i++){
		ll a, b; cin >> a >> b;
		ev.pb({{a, 0}, i});
		xini[a]++;
		ev.pb({{b, 1}, i});
	}
	sort(ev.begin(), ev.end());
	map<int, ll> mp;
	ll range = 0;
	ll x1 = ev[0].f.f;
	bool ini = true;
	set<int> st;
	set<ll> vis;
	for(int i=0;i <ev.size(); i++){
		auto IT = ev[i];
		bool flag = IT.f.s; ll x = IT.f.f; int id = IT.s;
		
		
		if(x != x1 or i==0){
	//		cout << x << " <-x  sz-> " << st.size() << " xini-> " << xini[x] << endl;
			mp[(int)st.size()+xini[x]]++;
			if(x!=0) mp[(int)st.size()]+= x-x1-1;
		}
		
		if(!flag){
			st.insert(id);
		}
		else{
			st.erase(id);
		}

		x1 = x;

	//	cout << "MAP" << endl;
	//	for(auto k : mp) cout << k.s << " ";
	//	cout << endl;
	
	}
	for(int i=1;i <=n; i++){
		cout <<mp[i] <<" ";
	}
	cout << endl;
	
	
	exit(0);
}
