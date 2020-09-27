#include <iostream>

using namespace std;


int main(){
	char plano;
	double sal;

	for(int i=1; i<=50; i++){
		cout << "Digite o plano do funcionário " << i << endl;
		cin >> plano;
		cout  << "Digite o salário atual do funcionário" << endl;
		cin >> sal;
		cout << endl;

		switch(plano){
			case 'A':
				cout << "O novo salário é: " << sal + 0.1*sal << endl;
				break;
			case 'B':
				cout << "O novo salário é: " << sal + 0.15*sal<< endl;
				break;
			case 'C':
				cout << "O novo salário é: " << sal + 0.2*sal<< endl;
				break;
		}
		cout << endl;
	}
	return 0;
}
