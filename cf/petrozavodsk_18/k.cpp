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

int main(){ _
	int n; cin >> n;
	vector<int> dg(n), v(n), can(n);
	vector<ii> eg(n-1);
	for(auto &i : can) cin >> i;
	for(auto &i : eg) {
		cin >> i.f >> i.s, i.f--, i.s--;
		v[i.f]=i.f+1, v[i.s]=i.s+1, dg[i.f]++, dg[i.s]++;
	}
	
	auto resp = [&](){
		int x = n;
		set<int> st;
		/*for(auto [a, b] : eg) x^=v[a], x^=v[b], st.insert(v[a]), st.insert(v[b]);
		assert(x==0);
		assert(st.size()==n);
		cout << -1 << endl; exit(0);
		*/cout << n << endl;
		for(auto [a, b] : eg) cout << v[a] << " " << v[b] << endl;
		exit(0);
	};

	int cur = n;
	for(auto i : eg) cur^=v[i.f], cur^=v[i.s];
	if(cur==0) resp();

	vector<int> odd;
	for(int i=0;i <n; i++){
		if(can[i] and dg[i]%2) odd.pb(i);
	}

	if(odd.size()==0) return cout << -1 << endl, 0;
	int p2 = 1;
	while(p2<=n) p2*=2;
	//cout << cur << " " << odd.size() << endl;
	cur^=v[odd[0]];
	if(odd.size()==1){
		if(cur>n){
			v[odd[0]] = cur;
			resp();
		}
		else if(cur>=1){
			int x = cur-1;
			if(can[x]){
				v[x] += p2;
				v[odd[0]] = cur;
				resp();
			}
		}
		return cout << -1 << endl, 0;
	}
	else{
		if(odd.size()==2 and cur==v[odd[1]]){
			return cout << -1 << endl, 0;
		}
		int it = 1;
		if(cur==v[odd[it]]) it++;
		v[odd[0]] = cur+p2;
		v[odd[it]] += p2;
		resp();
	}


	
	exit(0);
}
