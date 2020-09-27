#include <iostream>

using namespace std;

int main(){

	int idade[10], peso[10];
	
	cout << "Digite a idade de 10 pessoas" << endl;
	for(int i=0; i<10; i++)
		cin >> idade[i];
	
	cout << "Digite o peso dessas mesmas 10 pessoas" << endl;
	for(int i=0; i<10; i++)
		cin >> peso[i];

	int resposta[10];
	int contador = 0;

	for(int i=0; i<10; i++){
		if(idade[i]>15 and peso[i]>50 and peso[i]<60){
			resposta[contador] = i+1;
			contador++;
		}
	}

	cout << "As pessoas com mais de 15 anos e peso entre 50 e 60 quilos são" << endl; 
	for(int i=0; i<contador; i++)
		cout << resposta[i] << " ";
	cout << endl;
	
	return 0;
}
