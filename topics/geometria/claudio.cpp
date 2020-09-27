#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld eps = 1e-9;

int main(){ _
	ll fp, fh;
	int it = 0;
	while(cin >> fp >> fh){
		it++;
		ll a = 5*fp + 6*fh;
		a/=2;
		ll v = a + 2 - fp - fh;

		cout << "Molecula #" << it << ".:." << endl;
		cout << "Possui " << v << " atomos e " << a << " ligacoes" << endl;
		cout << endl;	
	}


	exit(0);
}
