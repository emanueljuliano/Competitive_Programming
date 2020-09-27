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

const int MAX = 200010;
map<int, vector<int>> ma;
int n,m;

namespace seg1{
	ll seg[2 * MAX];
	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}
	ll query(int a, int b) {
		ll ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}
namespace seg2{
	int seg[2 * MAX];
	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}
	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}
namespace seg3{
	ll seg[2 * MAX];
	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}
	ll query(int a, int b) {
		//cout << a << " " << b << endl;
		ll ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}

namespace seg4{
	int seg[2 * MAX];
	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}
	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}

ll query(int i, int x){
	//cout << "entrou " << i << " "<< x << endl;
	ll ret = 0;
	int ini=max(m-i-1, i-m+1), end=min(n-1-(i-n+m), i+m-1);
	//cout << ini << " " << end << endl;
	if(m%2){
		if(i%2){
			ret += seg1::query(ini, end);
			ret -= (ll)x*seg2::query(ini, end);
		}
		else{
			ret += seg3::query(ini, end);
			ret -= (ll)x*seg4::query(ini, end);
		}
	}
	else{
		if(i%2){
		//	cout << "UE " << max(0, i-m+1) << " " <<  min(n-1, i+m-1) << endl; 
			ret += seg3::query(ini, end);
			ret -= (ll)x*seg4::query(ini, end);
		}
		else{
			ret += seg1::query(ini, end);
			ret -= (ll)x*seg2::query(ini, end);
		}
	}
	return ret;
}

void update(int i, int x){
	if(i%2){ // 1, 2
		seg1::update(i, x);
		seg2::update(i, 1);
	}
	else{ // 3, 4
		seg3::update(i, x);
		seg4::update(i, 1);
	}
}

// 1 2 3 4 5

int main(){ _
	cin >> n >> m;
	vector<int> v, w;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
		ma[-a].pb(i);
	}
	
	ll ans = 0;
	for(auto k : ma){
		int at = -k.f;
		for(int i=0;i <k.s.size(); i++){
			ans += query(k.s[i], at);
		}
		for(int i=0;i <k.s.size(); i++){
			update(k.s[i], at);
		}
	//	cout <<"Res = " << at << " " << ans << endl;
	//	for(int i=0;i <n; i++) cout << seg3::seg[n+i] << " ";
	//	cout << endl;
	//	for(int i=0;i <n; i++) cout << seg4::seg[n+i] << " ";
	//	cout << endl;
	}
	cout << ans << endl;

	exit(0);
}
