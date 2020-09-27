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
	int n; cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int a; cin >> a; v.pb(a);
	}

	int i1=0, i2=n-1, ans = 0;

	for(int i=0;i <n; i++){
		if(v[i]-i > v[i1]-i1) i1 = i;
		if(n-i-1 != i1 and v[n-i-1]-i > v[i2]-(n-i2-1)) i2 = n-i-1;
	}
	ans = max(ans, v[i1]+v[i2]+(i2-i1));
	
	i1 = 0, i2=n-1;
	for(int i=0;i <n; i++){
		if(v[n-i-1]-i > v[i2]-(n-i2-1)) i2 = n-i-1;
		if(n-i-1 != i2 and v[i]-i > v[i1]-i1) i1 = i;
	}
	ans = max(ans, v[i1]+v[i2]+(i2-i1));

	cout << ans << endl;
	
	
	exit(0);
}
