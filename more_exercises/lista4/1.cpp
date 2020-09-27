#include <iostream>

using namespace std;


int main(){	
	cout << "============Calculadora=============" << endl;
	cout << endl << "As seguintes operações são possíveis" << endl;
	cout  << "Adição, digite 1" << endl; 
	cout  << "Subtração, digite 2" << endl; 
	cout  << "Multiplicação, digite 3" << endl; 
	cout  << "Divisão, digite 4" << endl; 
	cout << "Sair do programa, digite 5" << endl;
	cout << endl;
	int opcao;
	int a, b;
	
	cin >> opcao;
	cout << endl;
	
	while( opcao!= 5){
		switch(opcao){
			case 1:
				cout << "a: ";
				cin >> a;
				cout << "b: ";
				cin >> b;
				cout << endl << a << "+" << b << " = " << a+b;				
				break;
			case 2:
				cout << "a: ";
				cin >> a;
				cout  << "b: ";
				cin >> b;
				cout << endl << a << "-" << b << " = " << a-b;
				break;
			case 3:
				cout << "a: ";
				cin >> a;
				cout  << "b: ";
				cin >> b;
				cout << endl << a << "*" << b << " = " << a*b;
				break;
			case 4:
				cout << "a: ";
				cin >> a;
				cout  << "b: ";
				cin >> b;
				cout << endl << a << "/" << b << " = " << double(a)/double(b);
				break;
			case 5:
				return 0;
		}
		cout << endl << endl << "Proxima opção: " << endl;
		cin >> opcao;
	}

	return 0;
}
