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
int G[110][110];

int grun(int x, int y){
	if(x==y or x==0 or y==0) return -1;
	int &ans = G[x][y];
	if(ans != -1) return ans;
	ans = 0;
	vector<int> ret;
	for(int i=x-1; i>0; i--){
		if(i!=y) ret.pb(grun(i, y));
	}
	for(int i=y-1; i>0; i--){
		if(i!=x) ret.pb(grun(x, i));
	}
	for(int i=1; i<min(x, y); i++){
		ret.pb(grun(x-i, y-i));
	}
	sort(ret.begin(), ret.end());
	int it = 0;
	for(auto k : ret) if(ans==k) ans++;
	return ans;
}

int main(){ _
	memset(G, -1, sizeof(G));
	int n; cin >> n;
	int ans = 0;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		if(a==b or a==0 or b==0){
			cout << "Y" << endl;
			exit(0);
		}
		else{
			ans ^= grun(a, b);
		}
	}
	if(ans) cout << "Y" << endl;
	else cout << "N" << endl;
	
	exit(0);
}
