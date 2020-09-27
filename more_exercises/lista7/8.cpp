#include <iostream>

using namespace std;

int main(){

	int v[20], pares[20], impares[20], par=0, imp=0;

	cout << "Digite os 20 números do vetor" << endl;	
	for(int i=0; i<20; i++)
		cin >> v[i];
	
	for(int i=0; i<20; i++){
		if(v[i]%2==0){
			pares[par] = v[i];
			par++;
		}
		else{
			impares[imp] = v[i];
			imp++;
		}
	}

	cout << endl << "Os pares são" << endl;
	for(int i=0; i<par; i++)
		cout << pares[i] << " ";
	cout << endl << "Os ímpares são" << endl;
	for(int i=0; i<imp; i++)
		cout << impares[i] << " ";
	cout << endl;
}
