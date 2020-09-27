#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define inf 0x3f3f3f3f
typedef long long ll;

vector<ll> v;
int n;


int main(){ _
	ll a;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.pb(a);
	}

	vector <int> fim(200100);
	fim[0] = 1;
	int tam = 1;
	for(int i=1; i<n; i++){
		if(v[i]<= v[i-1]){
			tam = 1;
			fim[i] = tam;
		}	else fim[i] = ++tam;
	}

	tam = 1;
	vector <int> com(200100);
	com[n-1] = 1;
	for(int i=n-2; i>=0; i--){
		if(v[i] >= v[i+1]){
			tam = 1;
			com[i] = tam;
		}
		else com[i] = ++tam;
	}
	int ans = 1;
	for(int i=0; i<n; i++) ans=max(ans, com[i]);
	for(int i=1; i<n-1; i++) if(v[i-1] < v[i+1]) ans = max(ans, fim[i-1] + com[i+1]);	

	cout << ans << endl;
	exit(0);
}
