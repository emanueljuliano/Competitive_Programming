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
const int MAX = 2e5+10;

int pal[MAX][27];

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n>> m;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<26; j++){
				pal[i][j] = 0;
			}	
		}

		string s; cin >> s;
		vector<int> x(27, 0);
		for(int i=0; i<n; i++){
			x[s[i]-'a']++;
			for(int j=0; j<26; j++){
				pal[i][j] = x[j];
			}
		}

		vector<int> p;
		vector<int> ans(26, 0);
		for(int i=0; i<m; i++){
			int a; cin >> a; a--;
			for(int j=0; j<26; j++){
				ans[j] += pal[a][j];
			}
		}
		for(int i=0; i<26; i++)
			ans[i] += pal[n-1][i];

		for(int i=0; i<26; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
