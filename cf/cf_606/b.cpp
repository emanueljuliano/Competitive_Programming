#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ //_
	int t;
	int n;
	cin >> t;
	int v[200200];
	for(int j=0; j<t; j++){
		set <int> s;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		int ans = 0;
		sort(v, v+n, greater<int>());
		for(int i=0; i<n; i++){
			int a = v[i];
			int soma = 0;
			while(a%2 == 0){
				soma+=1;
				a/=2;
			}
			if(!s.count(a)){
				 s.insert(a);
				ans += soma;
			}
		}
		 cout << ans << endl;
	}

	exit(0);
}
