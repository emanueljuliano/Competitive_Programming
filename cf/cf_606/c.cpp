#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;	
	cin >> t;
	for(int j=0; j<t; j++){
		string s;
		cin >> s;
		vector <int> ans;
		set <int> se;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='t' and s[i+1]=='w' and s[i+2]=='o' and s[i+3]=='n' and s[i+4]=='e'){
				se.insert(i+3);
			}
			else if(s[i]=='o' and s[i+1]=='n' and s[i+2] == 'e' and !se.count(i+1)){
				se.insert(i+2);
			}
			else if(s[i]=='t' and s[i+1]=='w' and s[i+2]=='o'){
				se.insert(i+2);
			}
		}
	
	cout << (int) se.size() << endl;
	if((int)se.size()==0) cout << endl;
	else{
		for(auto c : se)
			cout << c << " ";
		cout << endl;
	}
	}
	exit(0);
}
