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
	ld r, l; cin >> r >> l;
	ld maxi = 4*3.1415*r*r*r/3.0;
	cout << (int)(l/maxi) << endl;


	exit(0);
}
