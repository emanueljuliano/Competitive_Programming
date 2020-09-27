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
	int t; cin>> t;
	int cas = 0;
	int M[110][110];
	while(t--){
		cas++;
		int n; cin >> n;
		for(int i=0;i <n; i++){
			for(int j=0; j<n; j++){
				cin >> M[i][j];
			}
		}
		int trace = 0, r=0, c=0;
		for(int i=0;i <n; i++){
			trace+= M[i][i];
		}
		vector<int> ap(n+10, 0);
		for(int i=0; i<n; i++){
			bool flag = false;
			for(int j=0; j<=n; j++) ap[j] = 0;
			for(int j=0; j<n; j++){
				if(ap[M[i][j]] != 0) flag = true;	
				ap[M[i][j]]++;
			}
			r += flag;
		}
		for(int j=0; j<n; j++){
			bool flag = false;
			for(int j=0; j<=n; j++) ap[j] = 0;
			for(int i=0; i<n; i++){
				if(ap[M[i][j]] != 0) flag = true;	
				ap[M[i][j]]++;
			}
			c += flag;
		}
		cout << "Case #" << cas << ": " << trace << " " << r << " " << c << endl;


	}
	
	
	exit(0);
}
