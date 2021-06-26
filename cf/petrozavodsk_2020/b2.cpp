#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int z;
	cin >> z;

	vector<ll> fat(20);
	fat[0] = 1;
	for(ll i = 1; i < 20; i++)
		fat[i] = i * fat[i-1];
	while(z--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int& i : a)
			cin >> i;

		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) if(a[i] >= a[j])
				if((fat[a[i]] / fat[a[j]] / fat[a[i] - a[j]]) % 2 == 1) {
					//cout << "a[i] = " << a[i] << " a[j] = " << a[j] << endl;
					ans++;
				}
		cout << ans << endl;
	}

	return 0;
}
