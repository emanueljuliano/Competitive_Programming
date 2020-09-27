#include <iostream>

using namespace std;

int main(){

	int original[20], v[20];
	for(int i=0; i<20; i++){
		cin >> original[i];
		v[i] = original[i];
	}
	for(int i=0; i<10; i++)	
		for(int j=0; j<9; j++)
			if(v[j]>v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
	for(int i=10; i<20; i++)	
		for(int j=10; j<20; j++)
			if(v[j]<v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}

	cout << "O vetor original é" << endl;
	for(int i=0; i<20; i++)
		cout << original[i] << " ";
	cout << endl;
	cout << "O vetor ordenado fica " << endl;
	for(int i=0; i<20; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}
