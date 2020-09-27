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
	int n; cin >> n;
	string s, ans; cin >> s;
	ans.pb(s[0]);
	for(int i=1; i<n; i++){
		char c = s[i];
		char c2 = s[i-1];
		if(c=='a' or c=='e' or c=='i' or c=='u' or c=='o' or c=='y')
			if(c2=='a' or c2=='e' or c2=='i' or c2=='u' or c2=='o' or c2=='y')
				continue;
		ans.pb(c);
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
