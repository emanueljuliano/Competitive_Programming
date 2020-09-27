#include <iostream>

using namespace std;

int main(){
	int c;
	cout << "Digite o código do produto: " << endl;
	cin >> c;

	while(c!=0){
		switch(c){
			case 0:
				return 0;
			case 1:
				cout << "Alimento não-perecível" << endl;
				break;
			case 2: case 3: case 4:
				cout << "Alimento perecível" << endl;
				break;

			case 5: case 6:
				cout << "Vestuário" << endl;
				break;
	
			case 7:
				cout << "Higiene Pessoal" << endl;
				break;

			case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
				cout << "Limpeza de Utensílios" << endl;
				break;

			default:
				cout << "Código inválido" << endl;
				break;
		}
		cout << endl << "Digite o código do produto: " << endl;
		cin >> c;
	}
	return 0;
}
