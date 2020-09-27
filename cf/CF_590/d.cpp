#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);



int main(){ _
	string str;  
	char a;
	cin >> str;
	vector < set <int> > s(30);
	for(int i=0; i<str.size(); i++){
		s[str[i]%97].insert(i+1);
	}
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a, ini, fim, p;
		char l;
		cin >> a;
		if(a==1){
			cin >> p >> l;
			for(int i=0; i<26; i++){
				if(s[i].count(p)) s[i].erase(p);
			}
			s[l%97].insert(p);
		}
		if(a==2){
			cin >> ini >> fim;
			int count = 0;
			for(int i=0; i<26; i++){
				auto t = s[i].lower_bound(ini);
				if(*t<=fim and *t>=ini) count++;
			}
			cout << count << endl;
		}

	}

}
