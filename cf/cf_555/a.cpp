#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


typedef long long ll;

int main(){ _

	ll n;
	cin >> n;
	string s = to_string(n);
	int ans=s[0]-48;
	set <int> se;
	while(true){
		se.insert(n);
		n++;
		if(n%10==0)
			while(n%10==0){
				n/=10;
		}
		if(n < 10){
			for(int i=1; i<10; i++)
				se.insert(i);
			break;
		}
	}
	cout << (int)se.size() << endl;
	exit(0);
}
