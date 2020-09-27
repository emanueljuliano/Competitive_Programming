#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


typedef long long ll;

int main(){ _
	int ans=10;
	string s;
	cin >> s;
	if(s.size() <2) ans--;
	for(int i=1; i<s.size(); i++){
		ans += abs(int(s[i] - 48) - 9);
	}
	cout << ans << endl;
	exit(0);
}
