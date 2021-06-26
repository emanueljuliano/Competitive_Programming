#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	bool ans = true;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		if(s[0]=='L') ans ^=1;
	}
	
	if(ans) cout << "TRUTH" << endl;
	else cout << "LIE" << endl;
	
	
	exit(0);
}
