#include <iostream>

using namespace std;

int main(){

	int v[10], n, contador=0;

	cout << "Digite os elementos do vetor" << endl;
	for(int i=0; i<10; i++)
		cin >> v[i];
	
	cout << "Digite o valor de n" << endl;
	cin >> n;
	
	for(int i=0; i<10; i++){
		if(v[i]==n)
			contador++;
	}

	if(contador>0){
		cout << "O valor " << n << " apareceu " << contador << " vezes, digite outro número" << endl;
		cin >> n;
	}
	else
		cout << "O valor " << n << " não apareceu" << endl;

}
