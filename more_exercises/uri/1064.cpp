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
	double b=0, a;
	int ans = 0;
	for(int i=0;i <6; i++){
		cin >> a; if(a>0) ans++, b+=a;
	}
	cout << ans << " valores positivos" << endl;
	cout << setprecision(1) << fixed;
	cout << b/ans << endl;
	
	
	exit(0);
}
