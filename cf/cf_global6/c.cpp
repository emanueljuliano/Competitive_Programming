#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 500100;
vector <int> pv;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1){
		pv.pb(i);
		for (int j = i; j <= lim; j += i) divi[j] = i;
	}
}



int main(){ _
	int n, m;
	cin >> n >> m;

	if(n==1 and m==1){ cout << 0 << endl;exit(0);}
	vector<int> par;
	for(int i=1; i<1010; i++) par.pb(i*2);
	vector <int> x;
	for(int i=0; i<min(n, m); i++) x.pb(par[i]+1);
	for(int i=min(n, m); i<max(n, m); i++) x.pb(x[i-1]+1); 

	if(n>=m){
		for(int i=0; i<m; i++) cout << par[i] << " ";
		cout << endl;
		for(int i=1; i<n; i++){
			cout << x[i-1] << " ";
			for(int j=1; j<m; j++){
				cout << (x[i-1])*par[j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << 2 << " ";
		for(int i=0; i<m-1; i++) cout <<x[i] << " ";
		cout << endl;
		for(int i=1; i<n; i++){
			cout << par[i] << " ";
			for(int j=1; j<m; j++){
				cout << (x[j-1])*par[i] << " ";
			}
			cout << endl;
		}
	
	}	

	exit(0);
}
