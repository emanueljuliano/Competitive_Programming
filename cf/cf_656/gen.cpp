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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
//mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]){ _
	srand(atoi(argv[1]));
	cout << 1 << endl;
	int x = 5;
	cout << x << endl;
	for(int i=0; i<x; i++) cout << rand()%x+1 << " ";
	cout << endl;
	
	
	
	exit(0);
}
