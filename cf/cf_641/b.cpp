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

int n;
vector<int> v;
int pd[int(1e5)+10];
int rec(int ind){
	if(2*ind>n) return 1;
	if(pd[ind]!=-1) return pd[ind];
	int at = 1;
	for(int j=2*ind; j<=n; j+=ind){
		if(v[j]>v[ind]) at = max(at, 1+rec(j));
	}
	return pd[ind] = at;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i <=n; i++) pd[i] = -1;
		v.clear();
		v.pb(INF);
		for(int i=0;i <n; i++) {int a; cin >> a; v.pb(a);}
		int ans  = 1;
		for(int i=1; i<=n; i++){
			ans = max(ans, rec(i));
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
