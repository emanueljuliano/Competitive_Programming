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

ll n, k;
bool ans = true;
vector<ll> w;
void bi(ll x, int i){
	int j = 0;
	while(x>0){
		ll at;
		at = x%k;
		if(at==1) w.pb(j);
		if(at>1) ans = false;
		x = x/k;
		j++;
	}
}

int main(){ //_
	
	int t; cin >> t;
	while(t--){
		w.resize(0);
		ans  =true;
		cin >> n>> k;
		vector<ll> v;
		for(int i=0; i<n; i++){
			ll a; cin >> a;
			v.pb(a);
		}
		for(int i=0; i<n; i++)
			bi(v[i], i);

		if(!ans) {cout << "NO" << endl; continue;}
		if(w.size()<=1){cout << "YES" << endl;continue;}
		sort(w.begin(), w.end());
		for(int i=0; i<w.size()-1; i++)
			if(w[i]==w[i+1]){
				ans = false;
			}
		
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	
	
	
	exit(0);
}
