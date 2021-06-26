#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


const int LIM = 150;

ld dp[80][80][80][2];
bool trans[80][80][80][2];

ld f(int c, int h, int x, int t) {
	if (t == LIM) return 1; // repensar
	if (c == 75) return 1;
	if (h == 75) return 0;
	
	if (c + x > 75) {
		return 1 - f(h, c, 0, t+1);
	}
	ld &ret = dp[c][h][x][t%2];
	if (ret > -1) return ret;

	ld hold = 0, conti = 0;

	// hold
	if (x > 0) hold = 1 - f(h, c+x, 0, t+1);
	else hold = 0;

	// continue
	conti = (1-f(h, c, 0, t+1))/6;
	for (int d=2; d<=6; d++) conti += f(c, h, x+d, t+1)/6;

	if (hold > conti) trans[c][h][x][t%2] = 1, ret = hold;
	else trans[c][h][x][t%2] = 0, ret = conti;

	return ret;
}

int main(){ _
	int tt; cin >> tt;
	for (int t = LIM-1; t>=0; t--) 
		for (int c=0; c<=75; c++) 
			for (int h = 0; h<=75; h++) 
				for (int x = 0; x <=75; x++) 
					dp[c][h][x][t%2] = -5, f(c, h, x, t);

	while (tt--)  {
		int c, h, x; cin >> c >> h >> x;
		f(c, h, x, 0);
		if (trans[c][h][x][0]) cout << "H" << endl;
		else cout << "C" << endl;
	}
	
	
	exit(0);
}
