#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;



int main(){	_
	int q;
	int n;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		int v[200200];
		int resp = n;
		for(int j=1; j<=n; j++){
			cin >> v[j];
		}
		int w[200200];
		memset(w, -1, sizeof(w));
		for(int j=1; j<=n; j++){
			if(w[j]!=-1) continue;
			int c = 1;
			int at = j;	
			vector<int> lista;
			lista.push_back(at);
			while(v[at]!=j){
				at = v[at];
				lista.push_back(at);
				c+=1;
			}
			for(int k=0; k<lista.size(); k++){
				w[lista[k]] = c;
			}
			
		}
		for(int j=1; j<=n; j++){
			cout << w[j] << " ";
		}
		cout << endl;

	 }
	


	exit(0);
}
