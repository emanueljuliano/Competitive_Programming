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
		int at = 0;
		int it = 0;
		while((1<<it)<=n){
			it++;
		}
		it--;
		n--;
		n -= it;
		int s = 1;
		vector<int> ans;
		for(int i=it;i >0; i--){
			int maxi = n/i;
			if(maxi>0){
				n -= i*min(maxi, s);
				ans.pb(min(maxi, s));
				s += min(maxi, s);
			}
			else{
				ans.pb(0);
			}
		}
		cout << it << endl;
		for(auto k : ans) cout << k << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
