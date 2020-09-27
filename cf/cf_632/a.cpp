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
	int M[110][110];
	while(t--){
		bool at = true;
		int n, m; cin >> n >> m;

		if(m%2){
			for(int i=0;i <n; i++){
				for(int j=0;j <m; j++){
					M[i][j] = at;
					at = !at;
				}
			}
		}
		else{
			for(int j=0;j <m; j++){
				for(int i=0;i <n; i++){
					M[i][j] = at;
					at = !at;
				}
			}

		}

		if(n*m%2==0 and m%2) M[0][1] = 1;	
		else if(n*m%2==0) M[1][0] = 1;
		for(int i=0;i <n; i++){
			for(int j=0;j <m; j++){
				if(M[i][j]) cout << "B";
				else cout << "W";
			}
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
