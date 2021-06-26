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
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		ll mini=0, maxi = 0;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			maxi += (a+x-1)/x;
			mini+=a;
		}
		mini = (mini+x-1)/x;
		cout << mini << " " << maxi << endl;
	}
	
	
	
	exit(0);
}
