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
	int n, a, b; cin >> n >> a >> b;
	int x=-1, y=-1;
	for(int i=0;i <=n/a; i++){
		x = i, y = (n-x*a)/b;
		if(x*a+y*b == n) return cout << "YES" << endl << x << " " << y << endl, 0;
	}
	cout << "NO" << endl;
	
	
	
	exit(0);
}
