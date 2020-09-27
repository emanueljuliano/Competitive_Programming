#include <iostream>

using namespace std;

int main(){
	
	int maior=-1, menor=1e6, v[10];
	cout << "Programa que lê 10 números e diz qual o maior e qual o menor" << endl;

	for(int i=0; i<10; i++)
		cin >> v[i];
	
	for(int i=0; i<10; i++){
		if(v[i] > maior) 
			maior = v[i];
	
		if(v[i]<menor) 
			menor = v[i];
	}

	cout << "O maior elemento é " << maior << endl;
	cout << "O menor elemento é " << menor << endl;
	
	return 0;
}
