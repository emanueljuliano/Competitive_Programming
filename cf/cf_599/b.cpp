#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _
	int k, n;
	cin >> k;
	for(int j=0; j<k; j++){
		cin >> n;
		string s1, s2;
		cin >> s1;
		cin >> s2;
		char a = '1', b='1';
		int c=0;
		bool flag = true;
		for(int i=0; i<n; i++){
			if(s1[i]!=s2[i]){
				c++;
				if(c>2){
					cout << "NO" << endl;
					flag = false;
					break;
				}
				if(a=='1'){
					a = s1[i];
					b = s2[i];
				}
				else{
					if(s1[i]!=a or s2[i]!=b){
						cout << "NO" << endl;
						flag = false;
						break;
					}
				}
			}
		}
		if(c==1){
			 flag = false;
			cout << "NO" << endl;
		}
		if(flag)
			cout << "YES" << endl;

	}

	exit(0);
}
