#include <iostream>

using namespace std;

int main(){
	int n, v[10];
	
	cout << "Digite os elementos do vetor de 10 posições" << endl;
	for(int i=0; i<10; i++)
		cin >> v[i];

	cout << "Digite o número n" << endl;
	cin >> n;
	
	for(int i=0; i<10; i++)
		if(v[i]==n){
			cout << "Achei na posição " << i+1 <<endl;
			return 0;
		}

	cout << "Não achei" << endl;

	return 0;
}
