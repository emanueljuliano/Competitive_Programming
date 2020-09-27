#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, a, b, c;

int pd[4040];
int rec(int x){
	if(pd[x]!=-1) return pd[x];
	int aa=-INF, bb=-INF, cc=-INF;
	if(x==0) return 0;
	if(x<a and x<b and x<c) return -INF;
	if(x>=a) aa = 1+rec(x-a);
	if(x>=b) bb = 1+rec(x-b);
	if(x>=c) cc = 1+rec(x-c);
	return pd[x] = max(aa, max(bb, cc));
}

int main(){ _
	memset(pd, -1, sizeof(pd));
	cin >> n >> a >> b >> c;
	cout << rec(n) << endl;

	exit(0);
}
