#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _	
	int q;
	cin >> q;
	string s;
	for(int j=0; j<q; j++){
		cin >> s;
		int d=0, l=0, r=0, u=0;
		for(int i=0; i<s.size(); i++){
			if(s[i] == 'U') u++;
			if(s[i] == 'L') l++;
			if(s[i] == 'D') d++;
			if(s[i] == 'R') r++;
		}

		int mini = min(l, r);
		l = mini, r=mini;
		mini = min(u, d);
		u = mini, d=mini;
		if(l==0){
			if(u==0){
				cout << 0 << endl;
				cout << endl;
			}
			else{
				cout << 2 << endl;
				cout << "UD" << endl;
			}
		}else if(u==0){
			if(l==0){
				cout << 0 << endl;
				cout << endl;
			}
			else{
				cout << 2 << endl;
				cout << "LR" << endl;
			}
		}
		
		else{
			cout << l+r+d+u << endl;
			for(int i=0; i<l; i++)
				cout << "L";
			for(int i=0; i<u; i++)
				cout << "U";
			for(int i=0; i<r; i++)
				cout << "R";
			for(int i=0; i<d; i++)
				cout << "D";
			cout << endl;
		}
	}
	exit(0);
}
