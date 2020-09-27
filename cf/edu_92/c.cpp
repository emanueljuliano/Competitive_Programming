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
		vector<int> v(10);
		for(int i=0;i <s.size(); i++){
			v[s[i]-'0']++;
		}
		int ans = 0;
		for(int i=0;i <10; i++){
			for(int j=0; j<10; j++){
				bool flag = true;
				int at = 0;
				for(auto cc : s){
					int c = cc-'0';
					if(c==i and flag) flag=false, at++;
					else if(c==j and !flag) flag=true, at++;
				}
				if(i!=j) at -= !flag;
				
				ans = max(ans, at);
			}
		}
		cout << s.size() - ans << endl;
	}
	
	
	
	exit(0);
}
