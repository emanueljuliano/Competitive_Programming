#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))
#define pi 3.14159265

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld eps = 1e-9;

ld VB, B;

ld V(ld x){
	return VB * (x/B)* (x/B)* (x/B);
}

int main(){ _
	
	int t; cin >> t;
	for(int i=0; i<t; i++){
		ld n, l; cin >> n >> l;
		ld v = l/n;
				
		ld b, H; cin >> b >> B >> H;

		if(b==B){
			cout << v/(pi*b*b) << endl;
			continue;
		}

		ld dif = H;
		H = B*H/(B-b);
		dif = H - dif;

		VB = pi * B*B * H / 3.0;
//		cout << VB << " " << V(B) << " " << V(b) <<  endl;

		// v = Vx - Vb
		ld x= ((v + V(b)) / VB) * B*B*B;
		x = cbrt(x);

		ld ans = H/B*x - dif;
		
		cout << setprecision(2) << fixed;
		cout << ans << endl;
	}


	exit(0);
}
