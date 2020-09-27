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
		int n, k; cin >> n >> k;
		if(n%2 and k%2==0){cout << "NO" << endl; continue;}
		if(n%2 or (n%2==0 and k%2==0)){
			vector<int> ans;
			for(int i=0;i <k-1; i++){ans.pb(1); n--;}
			if(n<=0) cout << "NO" << endl;
			else{
				cout << "YES" << endl;
				for(auto x : ans) cout << x << " ";
				cout << n << endl;
			}
		}
		else{
			vector<int> ans;
			for(int i=0;i <k-1; i++){ans.pb(2); n-=2;}
			if(n<2) cout << "NO" << endl;
			else{
				cout << "YES" << endl;
				for(auto x : ans) cout << x << " ";
				cout << n << endl;
			}
		}
	}
	
	
	
	exit(0);
}
