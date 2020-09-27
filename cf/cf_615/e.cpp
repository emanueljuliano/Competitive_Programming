#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m;
	cin >> n >> m;
	vector<vector<int>> M(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int a; cin >> a;
			M[i].pb(a);
		}
	}
	vector<int> shift(n);
	int ans = 0;
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++) shift[i]=0;

		int at = 0, ind=0, maxi=0, atu=j-m+1;
		for(int i=0; i<n; i++){
			int x = M[i%n][j];
			if(x>(n-1)*m+j+1) continue;
		//	cout << j<< " " << x<< endl;	
			if(x%m==(j+1)%m){
				int dif = (i-x/m + n)%n;
				if(j==m-1){
					dif = (i-x/m+1 +n)%n;
				}
				shift[dif]++;
			}
		}
		for(int i=0; i<n; i++){
		//	cout << i << "  "<< shift[i] << endl;
			maxi = max(maxi, shift[i]-i);
		}

		ans += n;
		ans -= maxi;
	
	}
	if(n==1 and m==1){
		if(M[0][0]!=1) return cout << 1 << endl, 0;
		else return cout << 0 << endl, 0;
	}
	cout << ans << endl;


	exit(0);
}
