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
	string s; cin >> s;
	vector<int> v(26);
	for(int i=0;i <s.size(); i++){
		v[s[i]-'a']++;
	}
	for(int i=0;i <25; i++){
		int a = v[i]/2;
		v[i] -= 2*a;
		v[i+1]+=a;
	}
	string ans;
	for(int i=0;i <26; i++){
		for(int k=0; k<v[i]; k++)
			ans.pb(i+'a');
	}
	sort(ans.begin(), ans.end(), greater<>());
	cout << ans << endl;
	
	
	exit(0);
}
