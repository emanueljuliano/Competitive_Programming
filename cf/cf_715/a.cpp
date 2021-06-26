#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<string> v(3);
		vector cnt(3, vector<int>(2));
		for (int i=0;i <3; i++) {
			cin >> v[i];
			for (int j=0; j<2*n; j++) cnt[i][v[i][j]-'0']++;
		}
		string a, b;
		int digit;
		for (int i=0; i<3; i++) {
			if (min(cnt[i][0], cnt[(i+1)%3][0]) >= n) a = v[i], b = v[(i+1)%3], digit=0;
			if (min(cnt[i][1], cnt[(i+1)%3][1]) >= n) a = v[i], b = v[(i+1)%3], digit=1;
		}
		string ans;
		int i = 0, j = 0;
		while(true) {
			if((i<2*n and a[i]-'0'==digit) and (j<2*n and b[j]-'0'==digit)) {
				ans+=a[i], i++, j++;
			}
			else if (i<2*n and a[i]-'0' != digit) ans+=a[i], i++;
			else if (j<2*n and b[j]-'0' != digit) ans+=b[j], j++;
			else if (i>=2*n and j>=2*n) break;
			else if (j>=2*n) ans +=a[i], i++;
			else if (i>=2*n) ans +=b[j], j++;
		}
		while(ans.size()<3*n) ans+='0';
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
