#include <iostream>

using namespace std;


int main(){

	int opcoes[6]={0};
	int maior=-1, menor=1e9, i_maior, i_menor;
	cout << "Digite a opção de cada usuário, 0 para parar" << endl;
	int n;
	cin >> n;
	while(n!=0){
		opcoes[n]++;
		cin >>n;
	}

	for(int i=1; i<=5; i++){
		if(menor < opcoes[i]){
			menor = opcoes[i];
			i_menor = i;
		}
		if(maior > opcoes[i]){
			maior = opcoes[i];
			i_maior = i;
		}

		cout << opcoes[i] << " pessoas votaram na opção " << i << endl; 	
	}

	cout << "A opção mais votada foi a " << i_maior << endl;
	cout << "A opção menos votada foi a " << i_menor << endl; 

	return 0;
}
