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
	int n, m, k; cin >> n >> m >> k;
	set<ii> st;
	for(int i=0;i <m; i++){
		int a; cin >> a;
		st.insert({a, i});
	}
	int at = -1, nat=0;
	vector<int> ans;
	int sz = n;
	while(n--){
		ii aux = *st.rbegin(); st.erase(aux);
		int ma = aux.s;
		if(ma!=at){
			ans.pb(ma); at = ma; aux.f--;
			if(aux.f){ st.insert(aux); nat = 1;}
			else nat = 0;	
		}
		else if(ma==at and nat<k){
			ans.pb(ma); at = ma; aux.f--;
			if(aux.f){ st.insert(aux); nat++; }
			else nat=0;
		}
		else{
			if(st.empty()) break;
			ii aux2 = *st.rbegin(); st.erase(aux2); st.insert(aux);
			int ma = aux2.s;
			ans.pb(ma);
			at = ma;
			aux2.f--;
			if(aux2.f){ st.insert(aux2); nat=1; }
			else nat = 0;
		}
	}
	if(ans.size()!=sz) cout << -1 << endl;
	else{
		for(auto k : ans) cout << k+1 << " ";
		cout << endl;
	}
	
	exit(0);
}
