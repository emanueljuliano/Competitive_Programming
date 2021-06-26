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
	int n; cin >> n;
	vector<pair<int, int>> v;
	for(int i=0;i <n; i++){
		int x, y, z; cin >> x >> y >> z;
		v.pb({x+z, y+z});
		v.pb({x-z, y+z});
		v.pb({x-z, y-z});
		v.pb({x+z, y-z});
	}
	int x_mini = INF, x_maxi=-INF, y_mini=INF, y_maxi=-INF;
	for(auto [x, y] : v){
		x_mini = min(x_mini, x);
		x_maxi = max(x_maxi, x);
		y_mini = min(y_mini, y);
		y_maxi = max(y_maxi, y);
	}

	int l = max(x_maxi - x_mini, y_maxi-y_mini);
	cout << x_mini+(l+1)/2 << " " << y_mini+(l+1)/2 << " " << (l+1)/2 << endl;	


	exit(0);
}
