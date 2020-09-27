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
	ll x=0, y=0;
	for(int i=0;i <n; i++){
		int m; cin >> m;
		for(int i=0;i <m; i++){
			int a; cin >> a;
			if(m%2 and i==m/2){
				v.pb(a);
			}
			else if(i<m/2){
				x+=a;
			}
			else{
				y+=a;
			}
		}
	}
	sort(v.begin(), v.end(), greater<>());
	bool at = true;
	for(auto k : v){
		if(at) x+=k;
		else y+=k;
		at ^=1;
	}
	cout << x << " " << y << endl;
	
	
	exit(0);
}
