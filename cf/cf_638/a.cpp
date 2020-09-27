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
		int n; cin >> n;
		vector<ll> v, w, z;
		ll soma = 0;
		for(int i=1; i<=n; i++){
			v.pb(1<<i);
			soma += 1<<i;
		}
		ll soma2=v[n-1];
		for(int i=0;i <n/2-1; i++){
			soma2 += v[i];
		}	
		cout << abs(2*soma2 - soma) << endl;
	}
	
	
	
	exit(0);
}
