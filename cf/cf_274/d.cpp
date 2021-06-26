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
	ll n, l, x, y; cin >> n >> l >> x >> y;

	vector<ll> v(n);
	for(auto &i : v) cin >> i;
	set<ll> st;
	for(auto u : v) st.insert(u);
	int has_x=false, has_y=false, has_xy=false, has_yx = false;
	ll xy = 0, yx=0;

	for(auto u : v){
		if(st.count(u+x)) has_x = true;
	}
	for(auto u : v){
		if(st.count(u+y)) has_y = true;
	}
	for(auto u : v){
		if(st.count(u+x+y)) has_xy = true, xy=u+x;
	}
	for(auto u : v){
		if(st.count(u+y-x) and u+y<=l) has_yx = true, yx=u+y;
		if(st.count(u+y-x) and u-x>=0) has_yx = true, yx=u-x;
	}


	if(has_x and has_y){
		cout << 0 << endl;
	}
	else if(has_x){
		cout << 1 << endl;
		cout << y << endl;
	}
	else if(has_y){
		cout << 1 << endl;
		cout << x << endl;
	}
	else if(has_xy){
		cout << 1 << endl;
		cout << xy << endl;
	}
	else if(has_yx){
		cout << 1 << endl;
		cout << yx << endl;
	}	
	else{
		cout << 2 << endl;
		cout << x << " " << y << endl;
	}


	
	
	exit(0);
}
