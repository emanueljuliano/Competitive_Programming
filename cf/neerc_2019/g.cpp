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

const int MAX = 110;
int a[MAX], h[MAX], id[MAX];
int n;
vector<int> ans;

int f(int l, int r, int mov){
	int at = 0, mini = INF;
	for(int i=l; true; i+=mov){
		at += a[i];
		mini = min(mini, at);
		if(i==r) break;
	}
	return -mini;
}

bool g(int pos, int mov){
	if(pos<0 or pos >=n) return true;
	int at=0;
	bool found = false;
	vector<int> to_add;
	for(int i=pos; i<n and i>=0; i+=mov){
		at += a[i];
		if(h[i]){
			found = true;
			if(f(i, pos, -mov) <= h[i]) {
				ans.pb(id[i]);
				for(auto u : to_add) ans.pb(u);
				return g(i+mov, mov);
			}
			else to_add.pb(id[i]);
		}
	}
	if(!found) return true;
	return false;
}

int main(){ _
	int m; cin >> n >> m;	
	int mini = n, maxi = 0;

	for(int i=0;i <m; i++){
		int s, hi; cin >> s >> hi;
		s--; 
		mini = min(mini, s), maxi = max(maxi, s);
		h[s] = hi, id[s] = i;
	}
	
	for(int i=0;i <n; i++){
		cin >> a[i];
	}

	int pos = -2;
	for(int i=mini;i <=maxi; i++){
		if(g(i, 1) and g(i-1, -1)) {pos = i; break;}
		ans.clear();
		if(g(i, -1) and g(i+1, 1)) {pos = i; break;}
		ans.clear();
	}
	
	cout << pos+1 << endl;
	for(auto u : ans) cout << u+1 << " ";
	cout << endl;

	exit(0);
}
