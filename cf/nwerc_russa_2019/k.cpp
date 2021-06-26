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

const int MAX = 1e3+10;
char M[MAX][MAX];

typedef tuple<int, int, int, int> T;

T area(vector<int> v){
	T ret = tuple(0, 0, 0, 0);
	stack<int> s;
	v.insert(v.begin(), -1);
	v.insert(v.end(), -1);
	s.push(0);

	for(int i=0; i<(int)v.size(); i++){
		while(v[s.top()] > v[i]){
			int h = v[s.top()]; s.pop();
			int at = h*(i-s.top() - 1);
			if(at > get<0>(ret)){
				ret = tuple(at, h, s.top(), i-2);
			}
		}
		s.push(i);
	}
	return ret;
}
int n, m;


void solve(int x, int y, int up, int down, int left, int right){
	vector<int> v(m);
	vector<bool> cabo(m);
	T ans;
	int id = 0;
	for(int i=up;i <=down; i++) {
		for(int j=left; j<=right; j++){
			if(M[i][j]=='.' or (i==x and j==y)) v[j]++;
			else v[j] = 0;
		}
		if(i>=x){
			for(int j=left; j<=right; j++){
				if(v[j]==0) cabo[j] = 1;
				else if(cabo[j]) v[j] = 0;
			}
			for(int j=y-1; j>=left; j--) v[j] = min(v[j], v[j+1]);
			for(int j=y+1; j<=right; j++) v[j] = min(v[j], v[j-1]);

			/*if(M[x][y]=='A'){
				for(auto u : v) cout << u << " ";
				cout << endl;
			}*/
			T ret = area(v);
			if(get<0>(ret) > get<0>(ans)) ans = ret, id = i;
		}
	}
	
	auto [val, h, l, r] = ans;
//	cout << "Letra " << M[x][y] << " val = " << val << " id = " << id << " h = " << h << " l = " << l << " r = " << r << endl;
	for(int i=id-h+1; i<=id; i++){
		for(int j=l; j<=r; j++) if(M[i][j]=='.')
			M[i][j] = M[x][y]^32;
	}
	
	int nup=id-h+1, ndown=id, nleft=l, nright=r;
	
	auto solve2 = [](int up_, int down_, int left_, int right_){
		if(down_<up_ or right_<left_) return;
		//cout << up_ << " " << down_ << " " << left_ << " " << right_ << endl;
		for(int i=up_; i<=down_; i++) for(int j=left_; j<=right_; j++) if(M[i][j]!='.')
			return solve(i, j, up_, down_, left_, right_);
	};

	solve2(up, down, left, nleft-1);
	solve2(up, nup-1, nleft, nright);
	solve2(ndown+1, down, nleft, nright);
	solve2(up, down, nright+1, right);
}



int main(){ _
	cin >> n >> m;
	vector<tuple<int, int, int>> pos;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) {
		cin >> M[i][j];
		if(M[i][j] != '.') pos.pb({int(M[i][j]-'A'), i, j});
	}	
	sort(pos.begin(), pos.end());
	solve(get<1>(pos[0]), get<2>(pos[0]), 0, n-1, 0, m-1);
	
	//for(int i=0;i <n; i++) for(int j=0; j<m; j++) assert(M[i][j]!='.');
	for(int i=0;i <n; i++) {
		for(int j=0; j<m; j++) cout << M[i][j];
		cout << endl;
	}
	exit(0);
}
