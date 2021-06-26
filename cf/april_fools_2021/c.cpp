#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	if(s.size()<=2) return cout << "YES" << endl, 0;

	for(int i=2;i <s.size(); i++){
		int a = s[i-2]-'A'+1;
		int b = s[i-1]-'A'+1;
		int c = s[i]-'A'+1;
		//cout << a << " "<< b << " "<< c << endl;
		if(c != (a+b-2)%26+1) return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
	
	
	
	exit(0);
}
