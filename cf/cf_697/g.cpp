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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 2e5+10;
int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(MAX);
		for(int i=0;i <n; i++){
			int a; cin >> a; v[a]++;
		}

		for(int i=MAX-5; i+1; i--) if(v[i]){
			int maxi = 0;
			for(int j=2*i; j<MAX; j+=i) maxi = max(maxi, v[j]);
			v[i] = v[i]+maxi;
		}

		int ans = 0;
		for(int i=0;i <MAX; i++) ans = max(ans, v[i]);

		cout << n-ans << endl;
	}
	
	
	
	exit(0);
}
