#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6+10;

ll mdc(ll a, ll b) {
	return !b ? a : mdc(b, a % b);
}

ll mul(ll a, ll b, ll m) {
	return (a*b-ll(a*(long double)b/m+0.5)*m+m)%m;
}

ll expo(ll a, ll b, ll m) {
	if (!b) return 1;
	ll ans = expo(mul(a, a, m), b/2, m);
	return b%2 ? mul(a, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll d = n - 1;
	int r = 0;
	while (d % 2 == 0) {
		r++;
		d /= 2;
	}

	// com esses primos, o teste funciona garantido para n <= 2^64
	// funciona para n <= 3*10^24 com os primos ate 41
	for (int i : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if (i >= n) break;
		ll x = expo(i, d, n);
		if (x == 1 or x == n - 1) continue;

		bool deu = 1;
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) {
				deu = 0;
				break;
			}
		}
		if (deu) return 0;
	}
	return 1;
}

int main(){ _
	int n; cin >> n;
	while(n--){
		string a, b; cin >> a >> b;
		ll x=0, y=0;
		ll at = 1;
		int p1=0, p2=0;
		for(int i=a.size()-1;i+1; i--) if(a[i]=='.') p1 = a.size()-i-1;
		for(int i=b.size()-1;i+1; i--) if(b[i]=='.') p2 = b.size()-i-1;
		if(p1 < p2) for(int i=0;i <p2-p1; i++) a.pb('0');
		if(p2 < p1) for(int i=0;i <p1-p2; i++) b.pb('0');
		//cout << p1 << " " << p2 << endl;
		for(int i=a.size()-1; i>=0; i--){
			if(a[i]=='.') continue;
			x += (ll)(a[i]-'0')*at;
			at *= 10;
		}
		at = 1;
		for(int i=b.size()-1; i>=0; i--){
			if(b[i]=='.') continue;
			y += (ll)(b[i]-'0')*at;
			at *= 10;
		}
		ll c = mdc(x, y);
		x/=c, y/=c;
		//cout << x << " " << y << endl;
		//cout << c << endl;
		if(x==1 and y==1) cout << 2 << " " << 2 << endl;
		else if(x==1 or y==1) cout << "impossible" << endl;
		else if(prime(x) and prime(y)) cout << x << " " << y << endl;
		else cout << "impossible" << endl;
	}



	exit(0);
}
