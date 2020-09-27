#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	for(int k=0; k<n; k++){
		string s;
		cin >> s;
		int sum = 0;
		int zero = 0;
		int par = false;
		for(int i=0; i<s.size(); i++){
			int a = s[i]-'0';
			sum += a;
			if(a==0) zero++;
			if(a%2==0) par++;
		}
		if(zero == s.size()) cout << "red" << endl;
		else if(sum%3==0 and zero > 1) cout << "red" << endl;
		else if(sum%3==0 and zero==1 and par>1) cout << "red" << endl;
		else cout << "cyan" << endl;
	
	}


	exit(0);
}
