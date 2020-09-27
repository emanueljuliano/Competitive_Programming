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
const int MAX = 2e3 + 10;
const int S = 1e3+1;
int mx1, mx2, my1, my2;
int D[MAX][MAX];
map<ii, vector<int>> M;
/*
bool val(int x, int y){
	ii p = {x, y};
	if(D[p]!=0) return false;
	if(x > mx1+3) return false;
	if(x < mx2-3) return false;
	if(y > my1+3) return false;
	if(y < my2-3) return false;
	return true;
}

int bfs(int x, int y){
	queue<ii> q;
	q.push({x, y});
	D.clear();
	ii p = {x, y};
	D[p] = 0;
	int ans = INF;
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		x = aux.f;
		y= aux.s;
	//	if(M[x][y] != -2) cout << x << ", "<< y << " m= " <<M[x][y] <<" d= " << D[x][y] << endl;
	
		if(M.count({x, y})){
	//		cout << x << " xy " << y << endl;
	//		cout << "d = " << D[aux] << endl;
			for(int i=0;i <M[aux].size(); i++){
	//			cout << M[aux][i] << " ";
				if(M[aux][i] >= D[aux]){
					ans = min(ans, M[aux][i]);
				}
			}
	//		cout << endl;
		}
		if(val(x+1, y)){
			q.push({x+1, y});
			ii p = {x+1, y};
			D[x+1][y] = D[x][y]+1;
		}
		if(val(x, y+1)){
			q.push({x, y+1});
			ii p = {x, y+1};
			D[p] = D[x][y]+1;
		}
		if(val(x-1, y)){
			q.push({x-1, y});
			ii p = {x-1, y};
			D[p] = D[aux]+1;
		}
		if(val(x, y-1)){
			q.push({x, y-1});
			ii p = {x, y-1};
			D[p] = D[aux]+1;
		}
	}
	return ans;
}
*/
int main(){ _
	int t; cin >> t; int cs = 0;
	while(t--){ cs++; cout << "Case #" << cs << ": ";
		M.clear();
		int x, y; cin >> x >> y;
		string s; cin >> s;
/*		ii p = {x, y};
		M[p].pb(0);
		mx1 = x;
		mx2 = 0;
		my1 = y;
		my2 = 0;
*/
		if(2*s.size() < x+y){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		int ans = INF;
		if(x==0 and y==0) ans = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='N') y++; 
			else if(s[i]=='S') y--;
			else if(s[i]=='E') x++;
			else if(s[i]=='W') x--;
/*			ii p = {x+S, y+S};
			mx1 = max(mx1, x+S);
			mx2 = min(mx2, x+S);
			my1 = max(my1, y+S);
			my2 = min(my2, y+S);
			M[p].pb(1+i);
*/			if(abs(x)+abs(y) <= i+1) ans = min(ans, i+1);
		}
		if(ans==INF) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}
		
	exit(0);
}
