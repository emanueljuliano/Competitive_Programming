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
	ll n, m; cin >> n >> m;
	vector<ll> v;
	ll soma = 0;
	for(ll i=0;i <m; i++){
		ll a; cin >> a; v.pb(a);
		soma += a;
	}
	if(soma<n){
		cout << -1 << endl;
		exit(0);
	}
	vector<ll> ans;
	reverse(v.begin(), v.end());

	ans.pb(v[0]);
	ll somat = v[0];
	ll nsoma = soma;
	for(ll i=1; i<m; i++){
		ll novo = 0;
		if(v[i]>somat){
			novo = v[i] - somat;
			if(nsoma-v[i]+novo >= n) ans.pb(novo);
			else{
				novo = n - nsoma + v[i];
				ans.pb(novo);
				nsoma += novo;
				break;
			}
		}
		else{
			novo = 1;
			if(nsoma - v[i] + novo >= n) ans.pb(novo);
			else{
				novo = n - nsoma + v[i];
				ans.pb(novo);
				nsoma += novo;
				break;
			}
		}
		somat += novo;
		nsoma += novo-v[i];
	}
//	for(ll i=0;i<ans.size(); i++){
//		cout << ans[i] << " ";
//	}
//	cout << endl;
	for(ll i=ans.size(); i<m; i++){
		ans.pb(v[i]);
	}
	reverse(ans.begin(), ans.end());
	v = ans;
	soma = 0;
	for(ll i=0;i <m; i++){
		soma += v[i];
	}
	if(soma!=n){
		cout << -1 << endl;
		exit(0);
	}
	ll at = 1;
	for(ll i=0;i <m; i++){
		cout << at << " ";
		at += v[i];
	}
	cout << endl;
	exit(0);
}
