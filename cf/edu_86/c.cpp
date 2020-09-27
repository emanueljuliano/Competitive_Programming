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
	int t; cin >> t;
	while(t--){
		ll a, b, q;
		cin >> a >> b >> q;
		ll mul = a/__gcd(a, b)*b;
		vector<ll> mod(mul, 0), soma(mul, 0);
		ll cnt = 0;
		for(ll i=0;i <mul; i++){
			if(i%a%b != i%b%a){
				cnt++, mod[i]=1;
				soma[i]++;
			}
			if(i!=0)soma[i] += soma[i-1];
		}
		while(q--){
			ll l, r; cin >> l >> r;
		//	for(int l=0;l <1000; l++) for(int r=l; r<1000; r++){
			ll it1 = (mul+l-1)/mul * mul;
			ll it2 = r/mul * mul;
			ll ans = 0;
			//	cout << cnt << "  "<< it1 << " " << it2 << endl;
				ans = ((r-l+1)/mul) * cnt;
				if(abs(it1-l) + abs(r-it2) +1 >= mul){
					ans -= cnt;
					//l = it1-it2%mul;
					//it2 = r+1;
				}
				ans += soma[(it1-1+mul)%mul] - soma[(l-1)%mul];
				ans += soma[r%mul];
			//	for(int i=l; i<=r; i++){
			//		if(i%a%b != i%b%a) ans2++;
			//	}
			//	cout << ans2 << " <-2" << endl;
			//cout << ans << " <-1" << endl;
			cout << ans << " ";
		//	if(ans!=ans2) {cout << l << " <l " << r << " <r " << it1 << " <1 2> " << it2 << endl;
		//	cout << " 1->" << ans << " 2->" << ans2 << endl;
		//	}
		//}
		}
		cout << endl;
	
	}
	
	
	
	exit(0);
}
