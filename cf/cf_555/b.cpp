#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


typedef long long ll;

int main(){ _

	int n, num;
	string s;
	cin >> n;
	cin >> s;
		
	int mapi[10];
	for(int i=1; i<10; i++)
		cin >> mapi[i];

	bool flag = false;
	for(int i=0; i<n; i++){
		
		if(s[i]-48>=mapi[s[i]-48]){
			cout << s[i];
		}
		else{
			while(i<n and s[i]-48 <= mapi[s[i]-48]){
				cout << mapi[s[i]-48];
				i++;
			}
			for(i; i<n; i++)
				cout << s[i];
			break;
		}
	}

	cout << endl;	

	exit(0);
}
