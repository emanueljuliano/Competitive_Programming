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

vector<int> v;

int cnt = 0;
int solve(int l, int r, int c){
//	cout << l << " " << r << " " << c << endl;
	cnt += r-l+1;
	if(l==r) return v[l]!=c;
	int c1= 0, c2 = 0;
	int m = (l+r)/2;
	for(int i=l; i<=m; i++) if(v[i]!=c) c1++;
	for(int i=m+1; i<=r; i++) if(v[i]!=c) c2++;
	int a1 = c1 + solve(m+1, r, c+1);
	int a2 = c2 + solve(l, m, c+1);
	return min(a1, a2);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.clear();
		for(int i=0;i <n; i++){
			char a; cin >> a; v.pb(a-'a');
		}
		cout << solve(0, n-1, 0) << " " << cnt << endl;
		cnt = 0;
	}
	
	
	
	exit(0);
}
