#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;


int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	int MOD = 10;
	int n = rand()%MOD+1;
	cout << n << endl;
	for(int i=0;i <n; i++){
		int a = rand()%(2*n)+1, b = rand()%(2*n)+1;
		cout << a << " " << b << endl;
	}
	
	
	
	exit(0);
}
