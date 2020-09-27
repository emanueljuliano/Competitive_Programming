#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll soma =0;
		ll somax = 0;
		for(int i=0; i<n; i++){
			ll a;
			cin >> a;
			soma+=a;
			somax = somax xor a;
		}
		if (soma == 2*somax){
			cout << 0 << endl;
			cout << endl;
		}
		else{
			soma += somax;
			cout << 3 << endl;
			cout << somax << " " << soma << " " << 0 << endl;
		}
	}


	exit(0);
}
