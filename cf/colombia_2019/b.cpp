#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	vector<string> v;
	v.push_back(s);
	for(int i=0; i<s.size(); i++) {
		string at=s;
		for(int j=i; j+1; j--) at += s[j];
		v.push_back(at);
	}

	for(auto t : v) {
		bool show = true;
		for(int j=0; j<t.size()/2; j++) {
			if(t[j] != t[t.size()-1-j]) show = false;
		}
		if(show) return cout << t << endl, 0;
	}	
	
	
	exit(0);
}
