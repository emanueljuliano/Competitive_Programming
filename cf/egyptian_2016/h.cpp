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

int M[10][10][10];
int d[10][10][10];

bool val(int f, int y, int x){
	return f<10 and y>=0 and x>=0;
}

int dijkstra(int f, int x, int y){
	set<pair<ii, ii>> st;
	st.insert({{10-M[f][x][y], f}, {x, y}});
	while(!st.empty()){
		auto at = *st.begin();
		st.erase(at);
		int v = at.f.f, f=at.f.s, x=at.s.f, y=at.s.s;
		if(d[f][x][y] !=-1) continue;
		d[f][x][y]= v;
	//	cout << v << " " << f << " " << x << " " << y << endl;
		if(val(f+1, x, y)){
			int nv = v+10 - M[f+1][x][y];
		   	st.insert({{nv, f+1}, {x, y}});
		}
		if(val(f, x-1, y)){
			int nv = v+10 - M[f][x-1][y];
		   	st.insert({{nv, f}, {x-1, y}});
		}
		if(val(f, x, y-1)){
			int nv = v+10 - M[f][x][y-1];
		   	st.insert({{nv, f}, {x, y-1}});
		}
	}
	return d[9][0][0];
}

int main(){ _
	freopen("commandos.in", "r", stdin);
	int t; cin >> t;
	while(t--){
		memset(M, 0, sizeof(M));
		memset(d, -1, sizeof(d));
		int n; cin >> n;

		for(int i=0;i <n; i++){
			int f, x, y, h; cin >> f >>x >> y >> h; f--, x--, y--;
			M[f][x][y] = h;
		}
		cout << 10*(9+9+10) - dijkstra(0, 9, 9) << endl;
	}

	
	
	exit(0);
}
