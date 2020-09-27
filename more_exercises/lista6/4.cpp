#include <iostream>

using namespace std;


int main(){
	int num, maior=0, menor=1e9, q=0;	
	cout << "Digite quantos números quiser, 0 para parar" << endl;
	
	cin >> num;
	while(num!=0){
		if(num<0){
			cout << "Entrada inválida, valor negativo." << endl;
			return 0;
		}
		q++;
		if(num>maior) maior = num;
		if(num<menor) menor = num;
		cin >> num;
	}

	cout << "A quantidade de números é " << q << endl;
	cout << "O menor número é " << menor << endl;
	cout << "O maior número é " << maior << endl;

	return 0;
}
