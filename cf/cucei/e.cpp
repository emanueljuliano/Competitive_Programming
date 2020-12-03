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

struct DATA{
	int x, y, z, w, d, h, t;
};

bool inter(DATA a, DATA b){
	bool ret = true;
	if(a.x < b.x and a.w < abs(a.x-b.x)) ret=false;
	if(a.x > b.x and b.w < abs(a.x-b.x)) ret=false;
	if(a.y < b.y and a.d < abs(a.y-b.y)) ret=false;
	if(a.y > b.y and b.d < abs(a.y-b.y)) ret=false;
	if(a.z < b.z and a.h < abs(a.z-b.z)) ret=false;
	if(a.z > b.z and b.h < abs(a.z-b.z)) ret=false;
	return ret;
}

int main(){ _
	int X, Y, Z, q, t; cin >> X >> Y >> Z >> q >> t;

	vector<DATA> v;
	while(q--){
		int f; cin >> f;
		if(f==1){
			DATA a;
			cin >> a.x >> a.y >> a.z >> a.w >> a.d >> a.h >> a.t;
			a.w--, a.d--, a.h--;
			bool show = true;
			for(auto b : v) if(inter(a, b)) show = false;
			if(show) v.pb(a);
			else cout << -1 << endl;
		}
		else{
			int x1, y1, x2, y2, z; cin >> x1 >> y1 >> x2 >> y2 >> z;
			DATA a;
			a.x=x1, a.y=y1, a.z=1, a.w=x2-x1, a.d=y2-y1, a.h=z-1;
			vector<int> val(t+1);
			int ans = 0;
			for(auto b : v){
				if(inter(a, b) and !val[b.t]) ans++, val[b.t] = 1;
			}
			cout << ans << endl;
		}
	}
	
	
	
	exit(0);
}
