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
	ll n, x, y; cin >> n >> x >> y;
	ll a1 = y-n+1;
	if(a1<=0 or a1*a1+n-1<x) return cout << -1 << endl, 0;
	cout << a1 << endl;
	for(int i=0;i <n-1; i++) cout << 1 << endl;
	
	
	exit(0);
}
