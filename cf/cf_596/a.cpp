#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"


int main(){
	int a, b;
	cin >> a >> b;
	if(b == a+1){
		cout << a<<9 << " " << a*10+10 << endl;
	}
	else if(a==b)
		cout << a*10 << " " << a*10+1 << endl;
	else if(a==9 and b==1)
		cout << 99 << " " << 100 << endl;
	else
		cout << -1 << endl;

	exit(0);
}
