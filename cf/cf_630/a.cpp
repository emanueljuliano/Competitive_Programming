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
	int t; cin >> t;
	while(t--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x, y, x1, x2, y1, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		if(x2-x1==0 and (a!=0 or b!=0)){cout << "No" << endl; continue;}
		if(y2-y1==0 and (c!=0 or d!=0)){cout << "No" << endl; continue;}
		a = b-a;
		c = d-c;
		if(x+a>= x1 and x+a<=x2 and y+c>=y1 and y+c<=y2){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	
	
	
	exit(0);
}
