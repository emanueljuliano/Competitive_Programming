#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> a(n), b(n);
	int maxi = 0;
	for(auto &i : a) cin >> i, maxi = max(maxi, i);
	for(auto &i : b) cin >> i;
	int k; cin >> k;
	vector<int> es(k);
	ll ans = 0;
	for(auto &i : es) cin >> i, ans+=i;
	ans += k*maxi;
	cout << ans << endl;

}
