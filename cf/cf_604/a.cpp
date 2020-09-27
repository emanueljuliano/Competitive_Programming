#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _

	int n;
	cin >> n;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;		
		bool flag = true;
		for(int j=0; j<s.size()-1; j++){
			if(s[j]!= '?' and s[j] == s[j+1])
				flag = false;
			if(s[j]=='?'){
				if('a' != s[j-1] and 'a' != s[j+1])
					s[j] = 'a';
				else if('b' != s[j-1] and 'b' != s[j+1])
					s[j] = 'b';
				else if('c' != s[j-1] and 'c' != s[j+1])
					s[j] = 'c';		
			}
		}
			if(s[0]=='?'){
				if(s.size() == 1)
					s[0] = 'a';
				else{
					if(s[1]!= 'a')
						s[0] = 'a';
					else if(s[1]!= 'b')
						s[0] = 'b';
					else if(s[1]!= 'c')
						s[0] = 'c';
				}
			}
			if(s[s.size()-1]=='?'){
				int k = s.size()-1;
				if(s[k-1]!= 'a')
					s[k] = 'a';
				else if(s[k-1]!= 'b')
					s[k] = 'b';
				else if(s[k-1]!= 'c')
					s[k] = 'c';
			}
			
			if(flag)
				cout << s << endl;
			else
				cout << -1 << endl;
		}

	exit(0);
}
