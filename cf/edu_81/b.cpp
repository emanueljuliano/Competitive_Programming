#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin>> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		string s; cin >> s;
		int z = 0, u=0;
		vector<int> v;
		multiset<int> se;
		for(int i=0;i<n; i++){
			if(s[i]=='0') z++;
			else u++;
			se.insert(z-u);
		}
		if(z==u){
			if(se.count(x)){
				cout << -1 << endl;
			}
			else{
				cout << 0 << endl;
			}
		}
		else if(z>u){
			int ans = 0;
			if(x==0) ans++;
			for(auto a : se){
				if(a<=x and (x-a)%(z-u)==0){
					ans++;
				}
			}
			cout << ans <<endl;
		}
		else{
			int ans = 0;
			if(x==0) ans++;
			for(auto a : se){
				if(a>=x and (a-x)%(u-z)==0){
					ans++;
				}
			}
			cout << ans << endl;
		}
	}


	exit(0);
}
