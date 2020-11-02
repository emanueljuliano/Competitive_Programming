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

	int mod = 100;
	int n=rand()%mod+1, m=rand()%mod+1, a=rand()%mod+1, d=rand()%mod+1;
	cout << n << " " << m << " " << a <<" "  << d << endl;

	for(int i=0;i <m; i++){
		int t=rand()%mod+1;
		cout << t << " ";
	}
	cout << endl;
	
	
	
	exit(0);
}
