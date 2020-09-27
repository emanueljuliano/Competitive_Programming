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
	s.pb('a');
	for(int i=0; i<n/2; i++){
		if(i%2==0)
			s.pb('b'), s.pb('b');
		else
			s.pb('a'), s.pb('a');
	}
	for(int i=0; i<n; i++){
		cout << s[i];
	}
	cout << endl;

	exit(0);
}
