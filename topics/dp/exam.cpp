#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef long long ll;
typedef pair<int, int> ii;

vector<ii> v;
int d;
vector<int> ans;
bool pd[300][300];

bool rec(int x, int p){
	if(x<0) return false;
	if(x==0 and p==d) return true;
	if(p==d) return false;
	if(!pd[x][p]) return false;
	for(int i=v[p].f; i<=v[p].s; i++){
//		cout << x << " " << p << " " << i << endl;
		if(rec(x-i, p+1)){
			ans.pb(i);
			return pd[x][p] = true;
		}
	}
	return pd[x][p] = false;
}

int main(){ _
	memset(pd, true, sizeof(pd));
	int sum; cin >> d >> sum;
	for(int i=0; i<d; i++){
		int a, b; cin >> a >> b;
		v.pb({a, b});
	}
	if(rec(sum, 0) and ans.size()==d){
		cout << "YES" << endl;
		for(int i=d-1; i>=0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	else cout << "NO" << endl;
	exit(0);
}
