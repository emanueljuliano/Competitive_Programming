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

struct machine{
	ll d, p, r, g;
	ll prev=0;
	bool operator < (const machine m) const{
		return g<m.g;
	}
	ll cost (ll x){
		return  prev + g*(x-d);
	}
};

bool inter(machine m1, machine m2, machine m3){
	// l1 = m1.g*x + b1
	// l1(m1.d) = m1.prev;
	// b1 = m1.prev - m1.g*m1.d
	ll a1 = m1.g, a2 = m2.g, a3 = m3.g;
	ll b1 = m1.prev - m1.g*m1.d;
	ll b2 = m2.prev - m2.g*m2.d;
	ll b3 = m3.prev - m3.g*m3.d;
	
	// l1==l2 if x = (b2-b1)/(a1-a2)
	return __int128(b2-b1)*(a1-a3) >= __int128(b3-b1)*(a1-a2);
}

int main(){ _
	
	int tc = 1;
	ll n, c, d;
	while(true){
		cin >> n >> c >> d;
		if(!n) return 0;

		vector<machine> v(n);
		for(auto &i : v) cin >> i.d >> i.p >> i.r >> i.g;

		sort(v.begin(), v.end(), [](machine a, machine b){return a.d<b.d;});
		
		set<machine> st;
		ll ans = c;
		for(int i=0;i <n; i++){
			while(st.size()>=2){
				auto it2 = st.begin();
				auto it1 = it2++;
				machine m1 = *it1, m2 = *it2;
				if(m1.cost(v[i].d-1) <= m2.cost(v[i].d-1)) st.erase(m1);
				else break;
			}
			if(st.size()){
				machine m1 =  *st.begin();
				ans = max(ans, m1.cost(v[i].d-1));
			}
			
			if(v[i].p > ans) continue;
			
			v[i].prev = ans-v[i].p+v[i].r;
			if(!st.size()){
				st.insert(v[i]);
				continue;
			}	
			
			auto lo = st.lower_bound(v[i]);
			if(lo!= st.end() and (*lo).g == v[i].g){
				machine mlo = *lo;
				if(mlo.cost(v[i].d) > v[i].cost(v[i].d)) continue;
				st.erase(mlo);
			}
	
			// if m.g < m1.g < m2.g then intersection(m, m1) < intersection(m, m2)
			while(true){
				auto it2 = st.lower_bound(v[i]);
				if(it2==st.end()) break;
				auto it1 = it2++;
				if(it2==st.end()) break;
				machine m1 = *it1, m2 = *it2;
				if(inter(v[i], m1, m2)) st.erase(m1);
				else break;
			}
			
			// if m2.g < m1.g < m.g then intersection(m2, m1) < intersection(m2, m)
			while(true){
				auto it2 = st.lower_bound(v[i]);
				if(it2==st.begin()) break;
				it2--;
				if(it2==st.begin()) break;
				auto it1 = it2--;
				
				machine m1 = *it1, m2 = *it2;
				if(inter(m2, m1, v[i])) st.erase(m1);
				else break;
			}
			
			// if m2.g < m.g < m1.g then intersection(m2, m) < intersection(m2, m1)
			auto it2 = st.lower_bound(v[i]);
			if(it2!=st.begin() and it2!=st.end()){
				auto it1 = it2--;
				machine m1 = *it1, m2 = *it2;
				if(inter(m2, v[i], m1)) continue;
			}
			
			st.insert(v[i]);
		}

		for(auto m : st) ans = max(ans, m.cost(d));
		
		cout << "Case " << tc++ << ": " << ans << endl;
	}
	
	
	exit(0);
}
