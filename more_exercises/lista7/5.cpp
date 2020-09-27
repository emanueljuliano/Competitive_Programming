#include <iostream>

using namespace std;

int main(){
	
	int A[10], B[10], C[10];
	cout << "Lê 2 vetores diferentes com 10 números cada e faz as operações de soma, subtração e multiplicação" << endl;	

	for(int i=0; i<10; i++)
		cin >> A[i];
	for(int i=0; i<10; i++)
		cin >> B[i];

	cout << endl << "Soma" << endl;
	for(int i=0; i<10; i++)
		C[i] = A[i] + B[i];
	for(int i=0; i<10; i++)
		cout << C[i] << " ";
	cout << endl;

	cout << endl << "Subtração" << endl;
	for(int i=0; i<10; i++)
		C[i] = A[i] - B[i];
	for(int i=0; i<10; i++)
		cout << C[i] << " ";
	cout << endl;

	cout << endl << "Multiplicação" << endl;
	for(int i=0; i<10; i++)
		C[i] = A[i] * B[i];
	for(int i=0; i<10; i++)
		cout << C[i] << " ";
	cout << endl;

	return 0;
}
