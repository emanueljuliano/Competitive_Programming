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
	string s;cin >> s;
	s.pb('0');
	int ans = 0;
	bool m5 = false;
	for(int i=0;i <s.size()-1; i++){
		int a = s[i]-'0';
		if(m5){
			if(a>=5) ans += 9-a;
			else if(a==4 and (s[i+1]-'0')>=5) ans += 9-a;
			else ans+=a, m5=false;
		}
		else{
			if(a>5) m5 = true, ans+=11-a;
			else if(a==5){
				if((s[i+1]-'0')>=5) m5 = true, ans += 11-a;
				else ans += a;
			}
			else ans += a;
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
