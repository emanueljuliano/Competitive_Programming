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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int j=25; j>0; j--){
		for(int k=0; k<n; k++){
			for(int i=0; i<s.size(); i++){
				int c = s[i]-'a';
				if(c==j){
					int at = ans;
					if(i>0 and s[i-1]-'a' == j-1)
						ans++;
					else if(i<s.size()-1 and s[i+1]-'a' == j-1)
						ans++;
					if(ans>at){
						string s2;
						for(int x=0; x<s.size(); x++)
							if(x!=i) s2.pb(s[x]);
						i--;
						s = s2;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
