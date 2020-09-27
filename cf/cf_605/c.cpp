#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set <char> se;
	ll c=0;
	for(int i=0; i<k; i++){
		char a;
		cin >> a;
		se.insert(a);	
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		//cout << c << endl;
		//cout << ans << endl;
		if(!se.count(s[i])){
			ans+= c*(c+1) / 2;
			c = 0;
			continue;
		}
		c++;
	}
	ans += c*(c+1)/2;
	cout << ans << endl;

	exit(0);
}
