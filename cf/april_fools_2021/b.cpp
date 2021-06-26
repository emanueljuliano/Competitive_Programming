#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _

	string s; cin >> s;
	while(s.size()>1){
		int at = 0;
		for(auto c : s) at += (c-'0');
		s = to_string(at);
	}
	cout << s << endl;
	exit(0);
}
