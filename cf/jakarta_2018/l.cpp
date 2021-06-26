#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	ll k; cin >> k;
	string s; cin >> s;
	reverse(s.begin(), s.end());
	int n = s.size();
	ll at = 0;
	for(int i=0;i <s.size(); i++)
		if(s[i]=='1') at += (1ll << i);
	
	int ans = 0;
	if(at<=k) return cout << 0 << endl, 0;
	int sat = n-1;

	for(int i=n-2; i>=0; i--){
		if(s[i]=='1') at -= (1ll<<i), at -= (1ll<<sat), at+= 1ll<<(sat-1), ans++, sat--;
		if(at<=k) break;
	}
	while(at>k) at=(at>>1ll), ans++;

	cout << ans << endl;

	exit(0);
}
