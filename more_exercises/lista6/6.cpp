#include <iostream>

using namespace std;

int main(){
	int maior=0, q=0, n=0;
	cout << "Digite quantos números quiser, 0 para parar" << endl;
	cin >> n;
	while(n!=0){
		if(n>=100 and n<=200){
			q++;
			maior = max(maior, n);
		}
		cin >> n;
	}

	cout << "Existem " << q << " numeros entre 100 e 200" << endl;
	cout << "O maior entre os números é " << maior << endl;

	return 0;
}
