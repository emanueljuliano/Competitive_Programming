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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<pair<ll, ll>> fat;
		for(ll i=2; i*i<=n; i++) if(n%i==0){
			int s = 0;
			while(n%i==0) s++, n/=i;
			fat.pb({s, i});
		}
		if(n!=1) fat.pb({1, n});
		sort(fat.begin(), fat.end(), greater<>());

		cout << fat[0].f << endl;
		for(int i=0;i <fat[0].f-1; i++) cout<< fat[0].s << " ";
		ll other = fat[0].s;
		for(int i=1; i<fat.size(); i++) for(int j=0; j<fat[i].f; j++) other*=fat[i].s;
		cout<< other << endl;
	}
	
	
	
	exit(0);
}
