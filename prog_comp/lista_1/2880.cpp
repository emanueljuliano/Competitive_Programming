#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	string s1; cin >> s1;
	string s2; cin >> s2;
	int ans = 0;
	for(int i=0; i<=s1.size()-s2.size(); i++){
		bool flag = true;
		for(int j=0; j<s2.size(); j++){
			int a = s1[i+j]-'A';
			int b = s2[j]-'A';
			if(a==b) flag = false;
		}
		ans+=flag;
	}
	cout << ans << endl;


	exit(0);
}
