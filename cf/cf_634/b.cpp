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
		int n, a, b; cin >> n >> a >> b;
		string s;
		for(int i=0;i <n; i++){
			s.pb(char('a'+(i%b)));
		}
		cout << s << endl;
	
	}
	
	
	
	exit(0);
}
