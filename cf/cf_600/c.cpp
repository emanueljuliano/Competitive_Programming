#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ss second
#define ff first
#define pb push_back

typedef long long ll;

int main(){ _
	ll n, m;
	cin >> n >> m;
	vector <ll> v;
	ll a;
	for(ll i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	vector < vector< ll> > soma;
	for(ll i=0; i<m; i++){
		vector <ll> aux;
		ll c = 0;
		for(ll j=i; j<n; j+=m){
			if(!aux.empty())
				aux.pb(v[j] + aux[c-1]);
			else{
				aux.pb(v[j]);
			}
			c++;
		}
		soma.pb(aux);
	}	

	ll ans=0;
	for(ll k=0; k<n; k++){
		ans+= soma[k%m][k/m];
		cout << ans << " ";
	}
	cout << endl;



	exit(0);
}
