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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int x, y; cin >> x >> y;
		string s; cin >> s;
		int r=0, u=0, d=0, l=0;
		for(auto c : s){
			if(c=='R') r++;
			if(c=='U') u++;
			if(c=='L') l++;
			if(c=='D') d++;
		}
		if(x>=0 and r>=x and y>=0 and u>=y) cout << "YES" << endl;
		else if(x<=0 and l>=-x and y>=0 and u>=y) cout << "YES" << endl;
		else if(x>=0 and r>=x and y<=0 and d>=-y) cout << "YES" << endl;
		else if(x<=0 and l>=-x and y<=0 and d>=-y) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
