#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	int it = -1;
	for(int i=0;i <s.size(); i++) {
		if('0'<=s[i] and s[i] <= '9') it = i;
		else break;
	}

	if(it==-1) cout << -1 << endl;
	else {
		for(int i=0;i <=it; i++) cout << s[i];
		cout << endl;
	}
	
	
	
	exit(0);
}
