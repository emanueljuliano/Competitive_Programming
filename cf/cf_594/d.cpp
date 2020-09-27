#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;

int qual(char c){
	if (c=='(') return 1;
	if (c == ')') return -1;
}

int n;

int conta(string s){
	int c=0, at=0, mini=1000;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='(') at++;
		else at--;
		if(at<mini){mini = at; c = 1;}
		else if(at==mini) c++;
	}	
	return c;	
}

int main(){ _
	int maxi=0;
	string s;
	cin >> n;
	cin >> s;
	maxi = conta(s);
	int a = 1, b =1;
	string copy = s;
	int count = 0;
	for(int i=0; i<s.size(); i++){
		count += qual(s[i]);
	}
	if (count != 0){
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		exit(0);
	}
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			if (copy[i]==copy[j]) continue;
			swap(copy[i], copy[j]);
			if (conta(copy) > maxi){
				maxi = conta(copy);
				a = i+1;
				b = j+1;
			}
			swap(copy[i], copy[j]);	
		}
	}
	cout << maxi << endl;
	cout << a << " " << b << endl;

	exit(0);
}
