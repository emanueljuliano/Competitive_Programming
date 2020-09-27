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
	int a, b, c, d; cin >> a >> b >> c >> d;
	int ans = 0;
	if(d < b) ans--;
	ans = (ans+c-a+48)%24;
	int ans2 = (d-b+60)%60;
	if(ans==0 and ans2==0) ans+=24;
	cout << "O JOGO DUROU " << ans << " HORA(S) E " << ans2 << " MINUTO(S)" << endl;
	
	
	exit(0);
}
