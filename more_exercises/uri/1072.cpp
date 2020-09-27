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
	int ans = 0;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		if(a>=10 and a<=20) ans++;
	}
	cout << ans << " in" << endl;
	cout << n-ans << " out" << endl;
	
	
	
	exit(0);
}
