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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		s += "$$$$$$$$$";

		bool ans = false;
		bool f = false;
		for(int i=0;i <n; i++){
			if(i==0 and s[i]=='2') f = true;
			if(i==n-3 and f and s[i]=='0' and s[i+1]=='2' and s[i+2]=='0') ans = true;
		}
		f = false;
		for(int i=0;i <n; i++){
			if(i==0 and s[i]=='2' and s[i+1]=='0') f = true, i++;
			if(i==n-2 and f and s[i]=='2' and s[i+1]=='0') ans = true;
		}
		f = false;
		for(int i=0;i <n; i++){
			if(i==0 and s[i]=='2' and s[i+1]=='0' and s[i+2]=='2') f = true, i+=2;
			if(i==n-1 and f and s[i]=='0') ans = true;
		}
		f = false;
		for(int i=0;i <n; i++){
			if((i==0 or i==n-4) and s[i]=='2' and s[i+1]=='0' and s[i+2]=='2' and s[i+3]=='0') ans = true;
		}	

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
