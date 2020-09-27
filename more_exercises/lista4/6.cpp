#include <iostream>

using namespace std;


int main(){
	int opcao;
	int val = 0;
	int aux;

	cout << "Conta de uma pessoa" << endl << endl;
	cout << "Escolha uma entre as opções:" << endl;
	cout << "Sair do programa, digite 0" << endl;
	cout << "Deposito, digite 1" << endl;
	cout << "Retirada, digite 2" << endl;

	cout << endl;
	cin >> opcao;
	while(opcao != 0){
		switch(opcao){
			case 1:
				cout << "Valor do deposito: ";
				cin >> aux;
				val += aux;
				cout  << "Valor atual: " << val << endl;
				break;

			case 2:
				cout << "Valor do saque: ";
				cin >> aux;
				val -= aux;
				cout  << "Valor atual: " << val << endl;
				break;
		}		
		cout << endl<< "Opcao: " << endl;
		cin >> opcao;
	}



	return 0;
}
