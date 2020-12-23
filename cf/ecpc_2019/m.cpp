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

int main(){ 
	freopen("lis.in", "r", stdin); _		
	string s; cin >> s;
	if(s.size()==1) return cout << (s[0]-'0') << endl, 0;
	bool is_9 = true;
	for(auto c : s) if(c!='9') is_9 = false;
	if(is_9) return cout << s.size()*9 << endl, 0;
	int ans = s[0]-'1';
	ans += (s.size()-1)*9;
	cout << ans << endl;	
	exit(0);
}
