#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	ll n, m, k; cin >> n>> m >> k;
	vector<ll> a, b;
	for(ll i=0;i <n; i++){
		ll aux; cin >> aux;
		a.pb(aux);
	}
	vector<ll> v;
	v.pb(0);
	for(ll i=0;i <n; i++){
		v.pb(a[i]+v[i]);
	}


	for(ll i=0;i <m; i++){
		ll aux; cin >> aux;
		b.pb(aux);
	}
	vector<ll> w;
	w.pb(0);
	for(ll i=0;i <m; i++){
		w.pb(b[i]+w[i]);
	}
	//for(auto x:w) cout << x << " ";
	//cout << endl;
	ll ans = 0;
	for(ll i=1; i*i<=k; i++){
		if(k%i==0){
			ll p1 = 0, p2=0;
			if(i<=n)for(ll j=0;j <v.size()-i; j++){
				if(v[j+i]-v[j]==i){
					p1++;
				}
			}
			if(k/i<=m)for(ll j=0;j <w.size()-k/i; j++){
				if(w[j+k/i]-w[j]==k/i)
					p2++;
			}
//			cout << i << " " << p1 << " " << p2 << endl;
			ans+= p1*p2;
			if(i*i==k) break;
			p1 = 0, p2=0;
			if(k/i<=n)for(ll j=0;j <v.size()-k/i; j++){
				if(v[j+k/i]-v[j]==k/i)
				p1++;
			}
			if(i<=m)for(ll j=0;j <w.size()-i; j++){
				if(w[j+i]-w[j]==i)
				p2++;
			}
//			cout << i << " " << p1 << " " << p2 << endl;
			ans+=p1*p2;
		}
	}
	cout << ans << endl;
	exit(0);
}
