#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e5+10;
const int LOG = 17;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;	
vector<ii> v, aux;
vector<int> ips;
int seg[2 * MAX];

void build() {
	for(int i=n; i<2*n; i++) seg[i] = 0;
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
	seg[p += n] += x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}


ll pode(int d){
	int it2 = 0;
	ll ret = 0;
	build();
	update(v[0].s, 1);
	for(int i=0; i<n; i++){
		int y = v[i].s;
		update(y, -1);
		while(it2+1<n and v[it2+1].f - v[i].f<=d){
			it2++;
			y = v[it2].s;
			update(y, 1);
		}
		
		int up2 = lower_bound(ips.begin(), ips.end(), ips[v[i].s] -d) - ips.begin();
		int up1 = upper_bound(ips.begin(), ips.end(), ips[v[i].s] +d) - ips.begin() -1;
		
		//for(int i=0;i <n; i++) cout << query(i, i) << " ";
		//cout << endl;
		int q = query(up2, up1);
		
		//cout << " rangex= [" << i << ", " << it2 <<
		//"] rangey= ["<< up2 << ", " << up1 << "] q= " << q << endl;
		
		ret = ret + q;	
	}
	return ret;
}


int main(){ _
	ll k; cin >>n >> k;
	for(int i=0;i <n; i++){
		int x, y; cin >> x >> y;
		v.pb({x+y, x-y});
	}
	sort(v.begin(), v.end());
	for(int i=0;i <n; i++) aux.pb({v[i].s, i});
	sort(aux.begin(), aux.end());
	for(int i=0;i <aux.size(); i++) ips.pb(aux[i].f);
	for(int i=0;i <n; i++) v[aux[i].s].s = i;


	//for(int i=0;i <n; i++) cout << v[i].f << " " << ips[v[i].s] << " " << v[i].s<< endl;
	//cout << endl;
	//int l = 0; int r = 10;
	int l = 0; int r = 4e8+10;
	while(l<r){
		int m = (l+r)/2;
		//cout << "m= " << m << endl;
		ll qt = pode(m);
		//cout <<  " ans= " << qt << endl << endl;
		if(qt<k) l = m+1;
		else r = m;
	}
	cout << l << endl;

	exit(0);
}
