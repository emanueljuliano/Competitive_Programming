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
	for(int i=0;i <n; i++){
		int a; cin >> a;
		v.pb(a);
	}	

	ll ans = 0;
	bool ac = true;
	for(int i=1;i <n; i++){
		if(v[i]<v[i-1]){
			ans += v[i-1]-v[i];
		}
	}
	ans += v.back();

	cout << ans << endl;


	exit(0);
}
