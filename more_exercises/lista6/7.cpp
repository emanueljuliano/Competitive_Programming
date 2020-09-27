#include <iostream>

using namespace std;


int main(){
	int inf, sup, soma=0;
	cout << "Digite o limite inferior e superior de um intervalo" << endl;
	cin >> inf >> sup;
	for(int i=inf; i<=sup; i++){
		if(i%2==0){
			soma+=i;
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "O somatório desses números é " << soma << endl;

	return 0;
}
