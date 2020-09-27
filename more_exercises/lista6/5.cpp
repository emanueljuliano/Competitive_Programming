#include <iostream>

using namespace std;

#define MAXN 10000

int main(){
	int multas_i[MAXN] = {0}, carteiras_i[MAXN] = {0};
	int n, multas, valor, soma=0, maior=-1, i_maior, carteira, n_multas;

	cout << "Digite o número de motoristas" << endl;
	cin >> n;

	for(int i=0; i<n; i++){
		cout << "Digite o número da carteira" << endl;
		cin >> carteira;
		cout << "Digite o número de multas" << endl;
		carteiras_i[i] = carteira;
		cin >> n_multas;
		cout << "Digite o valor de cada multa" << endl;
		for(int j=0; j<n_multas; j++){
			cin >> valor;
			multas_i[i] += valor;
		}

		if(multas_i[i] > maior){
			maior = multas_i[i];
			i_maior = carteira;
		}

		soma += multas_i[i];
	}
	for(int i=0; i<n; i++){
		cout << "O motorista " << carteiras_i[i] << " recebeu " << multas_i[i] << " reais de multa" << endl;
	}
	cout << "O motorista com a maior multa é o " << i_maior << endl;

	return 0;
}
