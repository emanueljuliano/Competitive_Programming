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
	int ans = 0;
	vector<char> v;
	for(int i=0;i <s.size(); i++){
		if(!v.empty() and v.back()==s[i]){
			v.pop_back();
			ans++;
		}
		else v.pb(s[i]);
	}
	if(ans%2) cout << "Yes" << endl;
	else cout <<"No" << endl;
	
	
	
	exit(0);
}
