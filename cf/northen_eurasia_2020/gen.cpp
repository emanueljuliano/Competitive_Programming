#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(int argc, char** argv){ _
	srand(atoi(argv[1]));
	
	int n = rand()%5 + 1;
	cout << n << endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<8; j++) {
			int c = rand()%2;
			if (c) cout << "W";
			else cout << "R";
		}
		cout << endl;
	}
	
	
	exit(0);
}
