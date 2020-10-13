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
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	
	set<ll> sum;
	sum.insert(0);
	int ans = 0;
	ll at = 0;
	for(int i=0;i <n; i++){
		at += v[i];
		if(sum.count(at)){
			ans++;
			sum.clear();
			at = v[i];
			sum.insert(0);
			sum.insert(at);
		}
		else sum.insert(at);
	}
	
	cout << ans << endl;
	
	exit(0);
}
