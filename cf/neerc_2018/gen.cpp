#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main(int argc, char** argv){ _
	srand(atoi(argv[1]));
	int p = 5;
	int n=rand()%p+1, m=rand()%p+1, a=rand()%p+1, d=rand()%p+1;
	cout << n << " " << m << " " << a << " " << d << endl;
	for(int i=0;i <m; i++){
		int x = rand();
		cout << x%(p*p)+1 << " ";
	}
	cout << endl;
	
	exit(0);
}
