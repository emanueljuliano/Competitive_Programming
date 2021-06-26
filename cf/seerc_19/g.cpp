#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> T;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e2+10;
int M[MAX][MAX], N[MAX][MAX];

int main(){ _
	int n, m, h; cin >> n >> m >> h;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		for(int j=0;j <m; j++)
			M[i][j] = s[j]=='1';
	}	
	for(int i=0;i <n; i++){
		string s; cin >> s;
		for(int j=0;j <h; j++)
			N[i][j] = s[j]=='1';
	}	
	
	vector<T> mini, maxi;
	for(int i=0;i <n; i++){
		vector<int> v1, v2;
		for(int j=0;j <m; j++) if(M[i][j]) v1.pb(j);
		for(int j=0;j <h; j++) if(N[i][j]) v2.pb(j);
		int n1 = v1.size(), n2 = v2.size();

		if(!n1 != !n2) return cout << -1 << endl, 0;
		if(!n1) continue;

		for(auto x : v1) for(auto y : v2) maxi.pb({i, x, y});
		if(n1 >= n2){
			for(int j=0; j<n1-n2; j++){
				mini.pb({i, v1[j], v2[0]});
			}
			for(int j=n1-n2; j<n1; j++){
				mini.pb({i, v1[j], v2[j-n1+n2]});
			}
		}
		else{
			for(int j=0; j<n2-n1; j++){
				mini.pb({i, v1[0], v2[j]});
			}
			for(int j=n2-n1; j<n2; j++){
				mini.pb({i, v1[j-n2+n1], v2[j]});
			}
		}
	}

	sort(mini.begin(), mini.end());
	sort(maxi.begin(), maxi.end());
	
	cout << maxi.size() << endl;
	for(auto [x, y, z] : maxi) cout << x << " "<< y << " " << z << endl;
	cout << mini.size() << endl;
	for(auto [x, y, z] : mini) cout << x << " "<< y << " " << z << endl;


	exit(0);
}
