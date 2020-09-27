#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(int &i: v) cin >> i;
	sort(v.begin(), v.end());
	int ans = 0;
	int it = n/2;
	for(int i=0; i<n/2; i++){
		while(it<n and v[it]<2*v[i]) it++;
		if(it<n) ans++;
		it++;
	}
	cout << n-ans << endl;


	exit(0);
}
