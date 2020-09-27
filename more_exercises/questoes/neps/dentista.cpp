#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, res=0, ult_fim=-1, at_ini, at_fim;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> at_ini >> at_fim;
		
		if(ult_fim <= at_ini){ // se a nova consulta começa depois que a anterior termina
			ult_fim = at_fim;
			res+=1;
		}

		if(at_fim <= ult_fim){ // se a nova consulta termina antes da anterior
			ult_fim = at_fim;
		}
	}

	cout << res << endl;

}
