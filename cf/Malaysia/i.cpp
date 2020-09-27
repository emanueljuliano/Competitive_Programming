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
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	char ans = '.';
	for(int i=0;i <3; i++){
		for(int j=0; j<s[i].size(); j++) if(s[i][j]=='='){
			for(int k=j+1; k<s[i].size(); k++) if(s[i][k]!='.'){
				ans = s[i][k]; break;
			}
			break;
		}
		if(ans!='.') break;
	}
	if(ans=='.') cout << "You shall pass!!!" << endl;
	else cout << ans << endl;
	
	
	
	exit(0);
}
