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

int main(){ _
	int n, m, k; cin >> n >> m >> k;
	if(m==1) return cout << n << endl, 0;
	vector<int> v(n);
	for(auto &i:v) cin >> i;
	sort(v.begin(), v.end());
	vector<int> off(n);
	int it = 0, op = 0, ans = 0;;
	for(int i=0;i<n; i++){
		op++;
		while(v[i]-v[it]+1>m) op-=!off[it], it++;
		if(op>=k) off[i]=1, op--, ans++;
	}
	cout << ans << endl;
	
	
	exit(0);
}
