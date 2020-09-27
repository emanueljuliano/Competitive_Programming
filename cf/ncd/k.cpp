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
		ll n, x; cin >> n >> x;
		vector<ll> v((int)n);
		for(auto &i: v) cin >> i;
		
		vector<ll> soma;
		soma.pb(0);
		for(int i=0;i <n; i++)
			soma.pb(soma.back()+v[i]);

		ll ans = 0;
		for(int i=0;i <n; i++){
			int l=i, r=n;
			while(l<r){
				int m = (l+r+1)/2;
				if(soma[m]-soma[i] >= x) r = m-1;
				else l = m;
			}
			ans += l-i;
		}
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
