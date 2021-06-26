#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int dif = 0;
		for (int i=0;i <n/2; i++) if(s[i] != s[n-1-i]) dif++;
		int z = 0;
		for (auto u : s) z += u == '0';
		if(!dif){
			if(z == 0) cout << "DRAW" << endl;
			else if(z==1 or z%2==0) cout << "BOB" << endl;
			else if(z%2==1) cout << "ALICE" << endl;
		}
		else if (dif == 1) {
			if (z == 2) cout << "DRAW" << endl;
			else  cout << "ALICE" << endl;
		}
		else cout << "ALICE" << endl;
	}
	
	
	
	exit(0);
}
