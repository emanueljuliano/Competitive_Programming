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


int main(){ _
	int n, m; cin >> n >> m;
	vector<int> ans(n);
	int at = 0;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		at += a;
		ans[i]+=at/m;
		at%=m;
	}
	for(auto x : ans) cout << x << " ";
	cout << endl;
	
	
	
	exit(0);
}
