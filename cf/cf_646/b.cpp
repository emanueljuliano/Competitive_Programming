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
		string s; cin >> s;
		int ans = INF;
		vector<int> soma;
		soma.pb(s[0]-'0');
		int tot = 0;
		for(int i=1;i <s.size(); i++){
			soma.pb(soma[i-1]+(s[i]-'0'));
		}
		tot = soma.back();
		for(int i=0; i<s.size(); i++){ // 10
			int at = i+1 - soma[i];	
			at += tot - soma[i];
			ans = min(ans, at);
		}
		for(int i=0; i<s.size(); i++){ // 01
			int at = soma[i];	
			at += s.size()-(i+1) - (tot-soma[i]);
			ans = min(ans, at);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
