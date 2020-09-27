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
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i=2; i<=100; i++){
			int i1 = 0, i2 = n-1;
			int at = 0;
			while(i1 < i2){
				if(v[i1]+v[i2] == i) at++, i1++, i2--;
				else if(v[i1]+v[i2]>i) i2--;
				else i1++;
			}
			ans = max(ans, at);
		}
		cout << ans << endl;
	
	
	}
	
	
	
	exit(0);
}
