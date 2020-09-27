#include <iostream>

using namespace std;

int main(){
	int n;
	
	cout << "Digite um numero" << endl;
	cin >> n;
	
	switch(n){
		case 1 : case 2 : case 3 : case 4 : case 5:
			cout << "O dia é um dia de semana" << endl;
			break;
		case 6 : case 7:
			cout << "O dia é fim de semana" << endl;
			break;
		default:
			cout << "Dia inválido" << endl;
	}
		 

	

	return 0;
}
