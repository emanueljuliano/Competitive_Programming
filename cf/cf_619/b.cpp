#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n;
		vector<int> v;
		cin >> n;
		int mum = 0;
		for(int i=0;i <n; i++){
			int a ; cin >> a;
			if(a==-1)mum++;
			v.pb(a);
		}
		int maxi = 0, mini = 0x3f3f3f3f;
		for(int i=0; i<n-1; i++){
			if(v[i]==-1 and v[i+1]!=-1){
				maxi = max(maxi, v[i+1]);
				mini = min(mini, v[i+1]);
			}
			if(v[i]!=-1 and v[i+1]==-1){
				maxi = max(maxi, v[i]);
				mini = min(mini, v[i]);
			}
		}
		if(mum==n) maxi = 0, mini=0;
		int ans = (maxi+mini)/2;
		int ans2 = 0;
		for(int i=0; i<n; i++){
			if(v[i]==-1)v[i] = ans;
		}
		for(int i=0; i<n-1; i++)
			ans2 = max(ans2, abs(v[i]-v[i+1]));
		cout << ans2 << " " << ans << endl;
	}



	exit(0);
}
