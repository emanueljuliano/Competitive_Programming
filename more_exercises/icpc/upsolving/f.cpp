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
	string s; cin >> s;

	vector<int> g(2), p(2);
	bool win=false, sac=false;
	for(auto c : s){
		if(c=='S') p[sac]++;
		else if(c=='R') p[!sac]++, sac=!sac;
		else {
			if(!win) {
				if(!sac) cout << g[0] << " (" << p[0] << "*) - " << g[1] << " (" << p[1] << ")" << endl;
				else cout << g[0] << " (" << p[0] << ") - " << g[1] << " (" << p[1] << "*)" << endl;
			}
			else{
				if(!sac) cout << g[0] << " (winner) - " << g[1] << endl;
				else cout << g[0] << " - " << g[1] << " (winner)" << endl;
			}
			continue;
		}
		if(p[sac]==10) g[sac]++, p={0, 0};
		else if(p[sac]>=5 and p[sac]>=p[!sac]+2) g[sac]++, p={0, 0};
		if(g[sac]==2) win = true;
	}
	
	
	
	exit(0);
}
