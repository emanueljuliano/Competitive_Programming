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


int main(){ _
	int x1, y1; cin >> x1 >> y1;
	int x2, y2; cin >> x2 >> y2;
	if(x1==x2) x1--;
	if(y1==y2) y1--;
	int ans =  2*(abs(x1-x2)+1 + abs(y1-y2)+1);
	cout << ans << endl;
	
	exit(0);
}
