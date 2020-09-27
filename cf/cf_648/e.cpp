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
const int MAX = 100;
vector<ll> v;
int n;
ll solve(int x){
	ll ret = v[x];
	ll aux = v[x];
	vector<int> ids(MAX, 0);
	int it=0;
	while(aux){
		if(aux%2==0) ids[it]=1;
		aux/=2;
		it++;
	}
	ll maxi = 0;
	for(int i=0;i <n; i++){
		aux = v[i];
		ll at = 0;
		it = 0;
		while(aux){
			if(aux%2 and ids[it]==1) at += (1<<it);
			it++;
			aux/=2;
		}
		if(at > maxi){
			maxi = at;
		}
	}
	ret += maxi;
	aux = maxi;
	it = 0;
	while(aux){
		if(aux%2==0 and ids[it]==1) ids[it]=2;
		aux/=2;
		it++;
	}
	maxi = 0;
	for(int i=0;i <n; i++){
		aux = v[i];
		ll at = 0;
		it = 0;
		while(aux){
			if(aux%2 and ids[it]==2) at += (1<<it);
			it++;
			aux/=2;
		}
		if(at > maxi){
			maxi = at;
		}
	}


	ret += maxi;
	return ret;

}

int main(){ _
	cin >> n;
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	sort(v.begin(), v.end(), greater<>());
	ll ans = 0;
	ans = solve(0);
	
	cout << ans << endl;
	
	
	exit(0);
}
