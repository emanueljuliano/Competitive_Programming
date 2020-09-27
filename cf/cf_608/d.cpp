#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m , k;
	cin >> n >> m >> k;
	vector <int> a, b, c;
	for(int i=0; i<n; i++){
		int a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		a.pb(a1);
		b.pb(b1);
		c.pb(c1);
	}
	int v[5050];
	for(int i=0; i<n; i++) v[i] = -1;
	for(int i=0; i<m; i++){
		int u1, v1;
		cin >> u1 >> v1;
		v[u1] = v1;
	}
	vector<int> soma;
	soma.pb(k);
	for(int i=0; i<b.size(); i++){
		soma.pb(soma[i-1]+b[i]);
	}
	vector<int> dif;
	for(int i=a.size()-1; i>=0; i--){
		
	}
	exit(0);
}
