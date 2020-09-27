#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld eps = 1e-9;

ll area(ll a, ll b, ll c){
	a = ld(a); b= ld(b); c = ld(c);
	ld p = ld(a+b+c)/2;
	if(p-a<eps or p-b<eps or p-c<eps) return -1;
	return  p*(p-a)*(p-b)*(p-c);

}

bool tri(ll a, ll b, ll c){
	if(a+b<=c or a+c<=b or b+c<=a) return false;
	return true;

}

int main(){ _
	ll n; cin >> n;
	vector<ll> v;
	multiset<ll> st;
	for(ll i=0;i <n; i++){
		ll a; cin >> a;
		v.pb(a);
		//st.insert(a);
	}
	n = v.size();
	ll l1, l2, l3;
	sort(v.begin(), v.end());
	for(int i=0;i <n-3; i++){
		if(tri(v[i], v[i+1], v[i+2])) l1=v[i], l2=v[i+1], l3=v[i+2];
	}

	//for(auto i : v) cout << i << " ";
	//cout << endl;

	//cout << ans << endl;
	cout << l1 << " " << l2 << " " << l3 << endl;
	
	
	
	exit(0);
}
