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

const int MAX = 2e6+10;

int divi[MAX];
vector<int> sh(MAX);

void crivo(){
	divi[0] = -1;
	for(int i=2;i <MAX; i++) divi[i] = i; 
	for(int i=2;i <MAX; i++) if(divi[i]==i)
		for(int j=i+i; j<MAX; j+=i) divi[j] = i;
		
	
	for(int i=2; i<MAX; i++){
		int aux = i;
		int fat = 1;
		int at = 1;
		sh[i] = sh[i-1];
		while(aux!=1){
			if(divi[aux] == divi[aux/divi[aux]]) at++;
			else fat*=(at+1), at=1;
			aux/=divi[aux];
		}
		if(divi[fat]==fat) sh[i]++;
	}
}

int main(){ _
	int n;
	crivo();
	while(cin >> n){
		cout << sh[n] << endl;

	}
	
	exit(0);
}
