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
	int cs = 0;
	while(true){
		cs++;
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if(a==-1) break;
		ll m1, m2, m3; m1=23, m2=28, m3=33;
		ll m = m1*m2*m3;
		ll b1, b2, b3; b1 =6, b2=19, b3=2;
		ll x = m/m1*b1*a + m/m2*b2*b + m/m3*b3*c;
		x%=m;
		//cout << "xi " << x << endl;
		if(x<=d) x+=m;
		cout << "Case " << cs << ": the next triple peak occurs in " << x-d << " days." <<  endl;

	
	}	
	
	
	
	exit(0);
}
