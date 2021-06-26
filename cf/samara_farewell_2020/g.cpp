#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	int k; cin >> k;
	vector<vector<int>> v(26);

	for (int i=s.size()-1; i+1; i--) 
		v[s[i]-'a'].push_back(i);
	
	int at = -1;
	string ans;
	while(k) {
		for (int i=0; i<26; i++) {
			while(v[i].size() and v[i].back()<at) v[i].pop_back();
			if(v[i].size() and s.size()-v[i].back()>=k){
				ans+=char('a'+i);
				k--;
				at = v[i].back(), v[i].pop_back();
				break;
			}
		}
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
