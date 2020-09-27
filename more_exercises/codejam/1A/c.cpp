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

int n, m;
vector<vector<int>> M;
bool show(int ii, int jj){
//	cout << ii << " " << jj << " hm " << endl;
	int div = 0;
	int soma = 0;
	for(int j=jj+1; j<m; j++) if(M[ii][j]!=0){
		soma += M[ii][j]; div++; break;
	}
	for(int j=jj-1; j>=0; j--) if(M[ii][j]!=0){
		soma += M[ii][j]; div++; break;
	}
	for(int i=ii+1; i<n; i++) if(M[i][jj]!=0){
		soma += M[i][jj]; div++; break;
	}
	for(int i=ii-1; i>=0; i--) if(M[i][jj]!=0){
		soma += M[i][jj]; div++; break;
	}
	if(div==0) return true;
	return (soma<= M[ii][jj]*div);
}


int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		cin >> n >> m;
		vector<vector<int>> M2(n, vector<int> (m, 0));
		M = M2;
		ll ans = 0;
		for(int i=0;i <n; i++){
			for(int j=0;j <m; j++){
				cin >> M[i][j];
				M2[i][j] = M[i][j];
			}
		}
		ll dif = 0;
		ll aux = 0;
		while(true){
			
			for(int i=0;i <n; i++) for(int j=0;j <m; j++) ans += M[i][j]; 
			if(ans == aux+dif) break;
			dif = ans - aux;
			aux = ans;

			for(int i=0;i <n; i++){
				for(int j=0;j <m; j++){
					if(!show(i, j)) M2[i][j] = 0;
				}
			}
		
			M = M2;
			//for(int i=0;i <n; i++){ for(int j=0; j<m; j++) cout << M[i][j] << " ";
		//		cout << endl;
		//	}
		}
		ans -= dif;
		cout << "Case #" << cs << ": ";
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
