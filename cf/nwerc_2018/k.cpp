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
	int n, m; cin >> n>> m;
	string s; cin >> s;
	string t; cin >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	
	string ans;
	ans+=s;
// b[n] = a[i] + a[i-n]
	for(int i=n;i <m; i++){
		int b = t[i]-'a';

		int novo =  (t[i-n]-ans[i-n]+26)%26;
		ans += novo+'a';
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
	
	
	exit(0);
}
