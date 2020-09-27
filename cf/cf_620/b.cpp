#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m;
	cin >> n >> m;
	vector<string> v;
	set<string> se;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		se.insert(s);
		v.pb(s);
	}
	vector<string> inv;
	vector<string> pal;
	for(int i=0; i<n; i++){
		string s = v[i];
		if(se.count(s))se.erase(s);
		string s2;
		for(int j=s.size()-1; j>=0; j--){
			s2.pb(s[j]);
		}
		if(s==s2) pal.pb(s);
		else if(se.count(s2)){
			se.erase(s2);
			inv.pb(s);
			inv.pb(s2);
		}
	}

	int ans = inv.size()*m;
	if(!pal.empty()) ans += m;
	cout << ans << endl;

	for(int i=0; i<inv.size(); i+=2){
		cout << inv[i];
	}
	if(!pal.empty()) cout << pal[0];
	
	for(int i=inv.size()-1; i>=0; i-=2)
		cout << inv[i];

	cout << endl;
	exit(0);
}
