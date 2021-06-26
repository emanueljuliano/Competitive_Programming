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
	ii nul = {0, 0};
	while(t--){
		vector<ii> pos;
		ii at = nul;
		string s; cin >> s;
		for(auto c : s){
			if(c=='L') at.f--;
			else if(c=='R') at.f++;
			else if(c=='U') at.s++;
			else if(c=='D') at.s--;
			pos.pb(at);
		}
		if(at==nul){
			cout << 5002 << " " << 5002 << endl;
			continue;
		}

		ii ans = nul;
		for(auto p : pos){
			if(p == nul) continue;
			at = nul;
			for(auto c : s){
				ii ant = at;
				if(c=='L') at.f--;
				else if(c=='R') at.f++;
				else if(c=='U') at.s++;
				else if(c=='D') at.s--;
				if(at==p) at = ant;
			}
			if(at==nul) ans = p;
		}
		cout << ans.f << " " << ans.s << endl;		

	}
	
	
	
	exit(0);
}
