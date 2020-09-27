#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0;i <n; i++){
		cin >> v[i];
	}
	int it1 = 0, it2 = 0;
	ll ans = 0;
	while(it2<n){
		while(it2<n and v[it1]==v[it2]) it2++;
		
		ll at = it2-it1;
		ans += at*(at+1)/2;
		it1=it2;
	}
	cout << ans << endl;


	exit(0);
}
