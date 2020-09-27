#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector <char> s1, s2;
	while(true){
		for(int i=0; i<m; i++){
			if(s1.size()>=n) break;
			s1.pb(s[i]);
		}
		if(s1.size()>=n) break;		
	}
	bool maior=false;
	for(int i=0; i<n; i++){
		if(s[i]>s1[i]) {maior = true; break;}
		if(s[i]<s1[i]) {maior = false; break;}
	}

	if(maior){
		vector <int> sm;
		for(int i=0; i<m; i++){
			sm.pb(s[i]-'0');
		}
		int flag = m-1;
		for(int i=m-1; i>=0; i--){
			if(sm[i]==9){
				sm[i]=0;
				flag = i-1;
			}
			else break;
		}
		sm[flag]+=1;
		
		s1.clear();
		while(true){
			for(int i=0; i<m; i++){
				if(s1.size()>=n) break;
				s1.pb('0'+sm[i]);
			}
			if(s1.size()>=n) break;		
		}
	}
	cout << s1.size() << endl;
	for(int i=0; i<s1.size(); i++)
		cout << s1[i];
	cout << endl;

	exit(0);
}
