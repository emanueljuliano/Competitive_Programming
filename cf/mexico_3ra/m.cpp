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
	for(auto & c : s) c--;
	vector<int> v(9);
	for(auto &i : v) cin >> i;
	
	vector<int> f(9);
	for(int i=0; i<s.size(); i++) f[s[i]-'0']++;

	int ans_size = s.size();
	for(auto u : v) ans_size-=u;

	string ans; int it = 0;
	while(ans_size--){
		for(int i=8; i+1; i--){
			vector<int> w(9); int p = -1;
			for(int j=it; j<s.size(); j++){
				if(s[j]=='0'+i) {p=j; break;}
				w[s[j]-'0']++;
			}
			if(p != -1 and f[i]>v[i]){
				bool show = true;
				for(int j=0; j<9; j++) if(w[j]>v[j]) show = false;
				if(show){
					ans+=(i+'1');
					while(it<p) v[s[it]-'0']--, f[s[it]-'0']--, it++;
					it++;
					f[i]--;
					break;
				}
			}
		}	
	}
	
	cout << ans << endl;
	
	
	exit(0);
}
