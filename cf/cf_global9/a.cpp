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
		bool sig = false;
		for(auto i : v){
			if(!sig){
				if(i<=0) cout << i << " ";
				else cout << -i << " ";
			}
			else{
				if(i>=0) cout << i << " ";
				else cout << -i << " ";
			}
			sig = !sig;
		}
		cout << endl;
	}	
	
	
	
	exit(0);
}
