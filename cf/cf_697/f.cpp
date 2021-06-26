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
		
		vector M(n, vector<bool> (n));
		vector N(n, vector<bool>(n));
		vector ans(n, vector<bool>(n)); 
		
		for(int i=0;i <n; i++){
			string s; cin >> s;
			for(int j=0; j<s.size(); j++) M[i][j] = (s[j]=='1');
		}
		for(int i=0;i <n; i++){
			string s; cin >> s;
			for(int j=0; j<s.size(); j++) N[i][j] = (s[j]=='1');
		}

		for(int i=0;i <n; i++){
			for(int j=0; j<n; j++) ans[i][j] = (M[i][j]!=N[i][j]);
		}

		vector<bool> v; v = ans[0];
		bool show = true;
		for(int i=1; i<n; i++){
			int dif = 0;
			for(int j=0; j<ans[i].size(); j++) dif+=(ans[i][j] != v[j]);
			if(dif!=0 and dif!=n) show = false;
		}

		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;


	}
	
	
	
	exit(0);
}
