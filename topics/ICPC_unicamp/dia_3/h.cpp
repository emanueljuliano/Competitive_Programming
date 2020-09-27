#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
typedef pair<int, int> pii;

int M[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, w, h;
vector<pii>hot;

void bfs(){
	queue < pii > q;
	for(int i=0; i<hot.size(); i++){
		q.push({hot[i].ff, hot[i].ss});
		M[hot[i].ff][hot[i].ss] = 0;
	}
	int count = 0;
	while(!q.empty()){
		pii x = q.front(); q.pop();
		count = M[x.ff][x.ss] + 1;
		for(int i=0; i<4; i++){
			int a = x.ff+dx[i];
			int b = x.ss + dy[i];
			if(a>=0 and b>=0 and a<w and b<h){
				if(M[a][b]==-1 or M[a][b]>count){
					M[a][b] = count;
					q.push({a, b});
				}
			}
		}
	}
}

bool check(int m){
	vector<pii> v;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(M[i][j]>=m){
				v.pb({i, j});
				break;
			}
		}
		if(v.empty())
			continue;
		for(int j=h-1; j>=0; j--){
			if(M[i][j]>=m){
				v.pb({i, j});
				break;
			}
		}

	}

	for(int i=0; i<v.size(); i++){
		pii v1 = v[i];
		for(int j=i+1; j<v.size(); j++){
			pii v2 = v[j];
			if(abs(v1.ff-v2.ff)+abs(v1.ss-v2.ss) >= m)
				return true;
		}
	}
	return false;
}

int bb(int l, int r){
	if(l==r) return l;
	int mid = 1+(l+r-1)/2;
	if(check(mid))
		return bb(mid, r);
	else
		return bb(l, mid-1);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(M, -1, sizeof(M));
		hot.resize(0);
		cin >> n >> w >> h;
		if(n==0) {cout << w+h-2 << endl; continue;}
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			hot.pb({a, b});
		}
		bfs();
/*		for(int j=0; j<h; j++){
			for(int i=0; i<w; i++){
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
*/
		cout << bb(0, 3000) << endl;
	}
}
