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
		ll aux2=0;
		ll n, p, k;
		vector<int> v;
		cin >> n >> p >> k;
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			v.pb(a);
		}
		ll resp = 0;
		sort(v.begin(), v.end());
		for(int i=0; i<k; i++){
			ll aux=p;
			ll ans = 0;
			if(aux2<=aux){ans=i;aux-=aux2;}
			else break;
			for(int j=i+k-1; j<n; j+=k){
				if(v[j]<=aux){ ans+=k; aux-=v[j];}
				else break;
			}
			resp = max(ans, resp);
			aux2+= v[i];
		}
		cout << resp << endl;
	}


	exit(0);
}
