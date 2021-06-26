#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;

int it = 0;
vector<tuple<int, int, int>> ans(MAX);

void solve(int a, int b) {
	//cout << a << " " << b << endl;
	int w, l=0, r=0;
	if (a <= 0 and b <= 0) return;
	if (b) w = 2, b--;
	else if(a) w = 1, a--;

	int bl = b/2, br = (b+1)/2;
	int al = (a+1)/2, ar = a/2;
	if (a and abs((2*bl + al) - (2*br + ar)) > 1) al++, ar--;
	if (abs((2*bl + al) - (2*br + ar)) > 1) {
		cout << -1 << endl;
		exit(0);
	}

	if (bl + al) l = it+2;
	if (br + ar) r = it+2+bl+al;
	ans[it] = {w, l, r};
	it++;
	solve(al, bl);
	solve(ar, br);
}

int main(){ _
	int a, b; cin >> a >> b;
	solve(a, b);
	
	for (int i=0; i<a+b; i++) {
		auto [w, l, r] = ans[i];
		cout << w << " " << l << " " << r << endl;
	}
	
	
	exit(0);
}
