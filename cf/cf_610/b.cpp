#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	for(int ii=0;ii<t; ii++){
		ll n, p, k;
		vector<int> v;
		cin >> n >> p >> k;
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		ll ans1=0, ans2=0;
		ll aux=p;
		for(int i=1; i<n; i+=2){
			if(v[i]<=aux){ ans1+=2; aux-=v[i];}
			else break;
		}
		aux = p;
		if(aux>=v[0]) ans2=1, aux-=v[0];
		for(int i=2; i<n; i+=2){
			if(v[i]<=aux){ ans2+=2; aux-=v[i];}
			else break;
		}
		cout << max(ans1, ans2) << endl;
	}


	exit(0);
}
