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

int main(){ _
	int t; cin >> t;
	while(t--){
			int n; cin >> n;
		vector<ll> v(n);
		ll a=0, b=0;
		for(auto &i : v) cin >> i;

		sort(v.begin(), v.end(), greater<>());

		for(int i=0;i <n; i++){
			if(i%2==0){
				if(v[i]%2==0) a+=v[i];
			}
			else{
				if(v[i]%2==1) b+=v[i];
			}
		}

		if(a>b) cout << "Alice" << endl;
		else if(a==b) cout << "Tie" << endl;
		else cout << "Bob" << endl;
	}
	
	
	
	exit(0);
}
