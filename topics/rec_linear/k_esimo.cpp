#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD=10;

vector<vector<ll>> mult(vector<vector<ll>> M1, vector<vector<ll>> M2){
	vector<vector<ll>> M3(2);
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			ll soma = 0;
			for(int k = 0; k<2; k++){
				soma += (M1[i][k]*M2[k][j]);
			}
			M3[i].push_back(soma%MOD);
		}
	}
	return M3;
}

vector<vector<ll>> fexp(vector<vector<ll>> M, ll k){
	if(k==1) return M;
	if(k%2==0) return fexp(mult(M, M), k/2);
	else return mult(M, fexp(M, k-1));
}

int main(){
	ll A, B, n, res;
	vector <vector <ll> > M(2);
	cin >> A >> B >> n >> res;
	for(int i=0; i<res-1; i++){
		MOD*=10;
	}
	M[0].push_back(A);
	M[0].push_back(B);
	M[1].push_back(1);
	M[1].push_back(A);
	if(n==1){
		cout << int(A+sqrt(B))%MOD / (MOD/10) << endl;
		exit(0);
	}
	

	vector<vector<ll>> Mn = fexp(M, n-1);
	cout << MOD << endl;
	cout << Mn[0][0] << " " << Mn[0][1] << endl;
	cout << Mn[1][0] << " " << Mn[1][1] << endl;
	
	ll xn = (Mn[0][0]*A + Mn[0][1]) % MOD;
	ll yn = (Mn[1][0]*A + Mn[1][1]) % MOD;
	ll resp = int(xn + yn*sqrt(B)) % MOD;
	
	cout << resp / (MOD/10) << endl;
	
}
