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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &i:v) cin >> i;
		int maxi = 0, mini = INF, id =-1;
		for(int i=0;i <n; i++){
			if(v[i]>maxi) maxi=v[i], id=i;
			mini = min(mini, v[i]);
		}
		int ans = 0;
		if(maxi==mini){cout << -1 << endl; continue;}
		for(int i=0;i <n; i++){
			if(v[i] == maxi){
				if(i and v[i-1] != maxi) {ans = i; break;}
				if(i!=n-1 and v[i+1] != maxi) {ans = i; break;}
			}
		}
		cout << ans+1 << endl;
	}
	
	
	
	exit(0);
}
