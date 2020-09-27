#include <iostream>

using namespace std;


int main(){
	int n, n_dp, val, idade;
	cout << "Numero de conveniados:" << endl;
	cin >> n;

	for(int i=0; i<n; i++){
		val = 100;
		n_dp;
		cout << "Numero de dependentes: " << endl;
		cin >> n_dp;
		for (int j=0; j<n_dp; j++){
			cout << "Idade do dependente " << j+1 << endl;
			cin >> n;
			if(n<10)
				val+= 80;
			else if(n<30)
				val += 50;
			else if(n<60)
				val += 95;
			else
				val += 130;	
		}
		cout << "O valor a ser pago pelo " << i+1 << " conveniado é de R$" << val << endl << endl;
	}


	return 0;
}
