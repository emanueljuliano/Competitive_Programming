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
	string s;
	int a, b, c, d;
	cin >> s >> a;
	cin >> b >> s >> c >> s >> d;
	int m = 60;
	int h = m*60;
	int di = h*24;
	int tot = a*di + b*h + c*m + d;
	cin >> s >> a;
	cin >> b >> s >> c >> s >> d;
	int tot2 = a*di + b*h + c*m + d;
	
	int ans = tot2-tot;
	cout << ans/di << " dia(s)" << endl;
	ans = ans%di;
	cout << ans/h << " hora(s)" << endl;
	ans = ans%h;
	cout << ans/m << " minuto(s)" << endl;
	ans = ans%m;
	cout << ans << " segundo(s)" << endl;
	
	
	
	exit(0);
}
