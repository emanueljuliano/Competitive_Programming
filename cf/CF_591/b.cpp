#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"


int main(){ _
	int n;
	string s, t;
	cin >> n;	
	for(int i=0; i<n; i++){
		cin >> s >> t;
		if(s.size()!=t.size()){ cout << "NO" << endl; continue;}

		if(s.size()==1 and s[0]!=t[0]) {cout << "NO" << endl; continue;}
		bool flag = false;
		for(int j=0; j<s.size(); j++){
			for(int k=0; k<t.size(); k++){
				if(s[j]==t[k]) flag = true;
			}	
		}
		if(flag)
			cout << "YES" << endl;
		else
			 cout << "NO" << endl;
	}



}
