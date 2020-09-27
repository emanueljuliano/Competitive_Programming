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
		int a, b; cin >> a >> b;
		int c, d; cin >> c >> d;
		if(c==b and a+d==c) cout << "Yes" << endl;
		else if(c==a and b+d==c) cout << "Yes" << endl;
		else if(d==a and c+b==d) cout << "Yes" << endl;
		else if(d==b and c+a==d) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	
	
	
	exit(0);
}
