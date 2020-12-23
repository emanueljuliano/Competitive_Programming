#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(int argc, char * argv[]){
    srand(atoi(argv[1]));
	int mx = 9;
	cout << rand()%mx+1 << " " << rand()%mx+1 << endl;
	return 0;
}
