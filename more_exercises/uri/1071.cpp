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
	int a, b; cin >> a >> b;
	int ans = 0;
	for(int i=min(a, b)+1; i<max(a, b); i++){
		if(i%2) ans += i;
	}
	cout << ans << endl;

	
	
	
	exit(0);
}
