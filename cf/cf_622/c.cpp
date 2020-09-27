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

ll func(int x, vector<ll> v){
	ll esq = 0;
	ll dir = 0;
	ll mini = v[x];
	for(int i=x-1; i>=0; i--){
		if(v[i]>mini){
			esq+=v[i]-mini;
		}
		else{
			mini = v[i];
		}
	}
	mini = v[x];
	for(int i=x+1; i<v.size(); i++){
		if(v[i]>mini){
			dir+=v[i]-mini;
		}
		else{
			mini = v[i];
		}
	}

	return esq+dir;
}

int main(){ _
	int n; cin>> n;
	vector<ll> v;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		v.pb(a);
	}

	ll at = 0;
	bool dec = false;
	bool crec = false;
	bool pode = true;
	for(int i=1; i<n; i++){
		if(v[i]>v[i-1] and dec) pode = false;
		else if(v[i]<v[i-1] and crec) dec = true;
	

		if(v[i]>v[i-1] and !dec and !crec){
			crec = true;
		}
		else if(v[i]<v[i-1] and !dec and !crec){
			dec = true;
		}
	}
	if(pode){
		for(int i=0; i<n; i++){
			cout << v[i] << " ";
		}
		cout << endl;
		exit(0);
	}
	
	ll mini = LINF;
	int id = 0;
	for(int i=0; i<n;i++){
		ll a = func(i, v);
		if(a<mini){
			mini = a;
			id = i;
		}
	}
	
	ll esq = 0;
	ll dir = 0;
	int x = id;
	at = v[x];
	vector<ll> ret = v;
	for(int i=x-1; i>=0; i--){
		if(v[i]>at){
			esq+=v[i]-at;
		}
		else{
			at = v[i];
		}
		ret[i] = at;
	}
	at = v[x];
	for(int i=x+1; i<n; i++){
		if(v[i]>at){
			dir+=v[i]-at;
		}
		else at = v[i];
		ret[i] = at;
	}
	
		for(int i=0; i<n; i++){
			cout << ret[i] << " ";	
		}
		cout << endl;

	exit(0);
}
