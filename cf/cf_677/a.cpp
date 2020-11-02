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
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int x = s[0]-'0';
		int ans = 0;
		ans = 10*(x-1);
		for(int i=1; i<=s.size(); i++) ans += i;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
