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

struct pt{
	ld x, y;
	pt(){}
	pt(ld x, ld y) : x(x), y(y) {}
};

ld dist(pt p, pt q){
	return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

int main(){ _
	int r1, x1, y1, r2, x2, y2;
	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
		pt c1(x1, y1);
		pt c2(x2, y2);
		if(dist(c1, c2) + r2 <= r1 + eps) cout << "RICO" << endl;
		else cout << "MORTO" << endl;
	}

	exit(0);
}
