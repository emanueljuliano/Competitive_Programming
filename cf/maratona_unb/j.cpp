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
	int n; cin >> n;
	string S; cin >> S;
	int r=0, p=0, s=0;
	for(auto c : S){
		if(c=='R') r++;
		if(c=='P') p++;
		if(c=='S') s++;
	}	
	
	vector<int> v = {s-p, r-s, p-r};
	sort(v.begin(), v.end());

	int ans = 0;
	if(s-p == v[2]) ans+=r;
	if(r-s == v[2]) ans+=p;
	if(p-r == v[2]) ans+=s;
	if(ans) return cout << ans << endl, 0;

	if(s-p == v[1]) ans+=r;
	if(r-s == v[1]) ans+=p;
	if(p-r == v[1]) ans+=s;
	if(ans) return cout << ans << endl, 0;
	
	if(s-p == v[0]) ans+=r;
	if(r-s == v[0]) ans+=p;
	if(p-r == v[0]) ans+=s;
	return cout << ans << endl, 0;
	
	exit(0);
}
