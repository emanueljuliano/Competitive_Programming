#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

vector<ii> v;
int w, h;
int D[1010][1010];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
bool val(int i, int j){
	return i>=0 and i<w and j>=0 and j<h and D[i][j]==-1;
}

void bfs(){
	queue<ii> q;
	for(auto i : v) q.push(i), D[i.f][i.s] = 0;
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		int i = aux.f, j = aux.s;
		for(int k=0; k<4; k++){
			int x = i+vx[k], y = j+vy[k];
			if(val(x, y)) q.push({x, y}), D[x][y] = D[i][j]+1;
		}
	}
}

bool val(int x){
	vector<ii> pts;
	for(int i=0;i <w; i++) for(int j=0; j<h; j++) if(D[i][j]>=x){
		pts.pb({i, j});
		break;
	}
	for(int i=0;i <w; i++) for(int j=h-1; j>=0; j--) if(D[i][j]>=x){
		pts.pb({i, j});
		break;
	}
	bool show = false;
	for(int i=0;i <pts.size(); i++) for(int j=i+1; j<pts.size(); j++){
			ii a = pts[i];
			ii b = pts[j];
			show |= abs(a.f-b.f)+abs(a.s-b.s) >=x;
	}
	
	return show;
}

int bb(int l, int r){
	if(r-l<=1){
		if(val(r)) return r;
		return l;
	}
	int m = (l+r)/2;
	if(val(m)) l = m;
	else r = m-1;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n >> w >> h;
		for(int i=0;i <=w; i++) for(int j=0; j<=h; j++)	D[i][j]=-1;
		v.resize(n);
		for(auto &i : v) cin >> i.f >> i.s;
		if(n==0){
			cout << h-1+w-1 << endl;
			continue;
		}	
		bfs();
		for(int i=0;i <w; i++){
//			for(int j=0; j<h; j++) cout << D[i][j] << " ";
//			cout << endl;
		}
		cout << bb(1, w*h) << endl;
	}

	exit(0);
}
