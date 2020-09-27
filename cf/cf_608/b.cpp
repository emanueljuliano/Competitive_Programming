#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> v;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='W') v.pb(1);
		else v.pb(0);
	}
	vector<int> v2 = v;
	vector<int> ans0;
	vector<int> ans1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]==0){
			ans0.pb(i+1);
			v[i] = 1;
			if(v[i+1]==1) v[i+1] = 0;
			else v[i+1] = 1;
		}
	}
	for(int i=0; i<v2.size()-1; i++){
		if(v2[i]==1){
			ans1.pb(i+1);
			v2[i] = 0;
			if(v2[i+1]==1) v2[i+1] = 0;
			else v2[i+1] = 1;
		}
	
	}
	if(v2[n-1]==0){
		cout << ans1.size() << endl;
		if(ans1.size()==0) return 0;
		for(int i=0; i<ans1.size(); i++) cout << ans1[i] << " ";
		cout << endl;
	}
	else if(v[n-1]==1){
		cout << ans0.size() << endl;
		if(ans0.size()==0) return 0;
		for(int i=0; i<ans0.size(); i++) cout << ans0[i] << " ";
		cout << endl;
	}
	else cout << -1 << endl;

	exit(0);
}
