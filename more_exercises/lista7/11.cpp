#include <iostream>

using namespace std;

int main(){

	int v[10], original[10];
	cout << "Digite 10 números" << endl;
	for(int i=0; i<10; i++){
		cin >> original[i];
		v[i] = original[i];
	}

	for(int i=0; i<10; i++){
		for(int j=0; j<9; j++)
			if(v[j]>v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
	}
	cout << "O vetor original é " << endl;
	for(int i=0; i<10; i++)
		cout << original[i] << " ";
	cout << endl; 
	cout << "O vetor ordenado é " << endl;
	for(int i=0; i<10; i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}
