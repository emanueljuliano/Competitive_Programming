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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	cout << 1 << endl;
	int na = 5;
	int n = rand()%na+1, m = rand()%na+1, k=n+m+rand()%na;
	cout << n << " " << m << " " << k << endl;
	
	string s;
	for(int i=0;i <k; i++) s+=char('A' + rand()%4);
	cout << s << endl;	
	
	exit(0);
}
