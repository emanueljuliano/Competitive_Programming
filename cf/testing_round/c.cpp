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
		set<pair<ii, ii>> st;
		string s; cin >> s;
		ii at = {0, 0};
		
		st.insert(at);
		int ans = 0;
		for(int i=0; i<s.size(); i++){
			auto nat = at;
			char x = s[i];
			if(x=='N') at.f++;
			else if(x=='S') at.f--;
			else if(x=='W')at.s++;
			else if(x=='E') at.s--;

			if(st.count({nat, at})) ans++;
			else ans+=5;
			st.insert({nat, at});
			st.insert({at, nat});
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
