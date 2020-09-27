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


int main(){ _
	int n; cin >> n;
	int M[3][3];
	int x = 1<<17;
	M[0][0] = n+x;
	M[0][1] = n;
	M[0][2] = n;
	M[1][0] = x+n;
	M[2][0] = x+n;
	M[1][1] = x;
	M[1][2] = x+n;
	M[2][1] = x;
	M[1][1] = x;
	M[2][2] = n;


	cout << 3 << " " << 3 << endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}

	exit(0);
}
