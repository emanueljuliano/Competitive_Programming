#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> arr(n);
		ll p = 0;
		ll w = 0;
		for (int i = 0; i < n; i++)cin>>arr[i];
		for (int i = 1; i < n; i++){
			bool flag = false;
			while(arr[i] + p < arr[i-1]){
				flag = true;
				p = (p == 0 ? 1 : p*2);
				w++;
			}
			if (flag) arr[i] += p;
		}

		cout << w << endl;
	}
	exit(0);
}
