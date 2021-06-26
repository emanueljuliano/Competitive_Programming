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
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		map<int, int> mp;
		for(auto u : v){
			mp[u]++;
		}
		bool win = false;
		int mini;
		for(auto [a, b] : mp){
			if(b==1) {
				win = true;
				mini = a;
				break;
			}
		}
		if(!win){
			cout << -1 << endl;
		}
		else{
			for(int i=0;i <n; i++) if(v[i]==mini) cout << i+1 << endl;	
		}
	}
	
	
	
	exit(0);
}
