#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin>>t;
	while(t--){
		int n; cin >> n;
		int p=0, s=0, m=0;
		vector<int> v;
		for(int i=0; i<n; i++){
			int a; cin >>a;
			v.pb(a);
			if(a==0) p++;
			if(a==-1) m++;
			s+= a;
		}
		int ans = p;
		if(ans!=0){
			s += p;
			if(s==0){
				ans++;
			}
		}
		else{
			if(s==0){
				ans++;
			}
		}
		cout << ans << endl;
	}


	exit(0);
}
