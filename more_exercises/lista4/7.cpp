#include <iostream>

using namespace std;


int main(){
	int cod, q;
	double val=0;
	cout << "Faça seu pedido" << endl;
	cout << "Código: 0 - Finalizar compra" << endl;
	cout <<"Código: 100 – Produto: Cachorro quente – Preço Unitário R$ 1,70" << endl;
	cout << "Código: 101 – Produto: Bauru Simples – Preço Unitário R$ 2,30" << endl;
	cout << "Código: 102 – Produto: Bauru com ovo – Preço Unitário R$ 2,60" << endl;
	cout << "Código: 103 – Produto: Hamburguer – Preço Unitário R$ 2,40" << endl;
	cout << "Código: 104 – Produto: Cheeseburguer – Preço Unitário R$ 2,50" << endl;
	cout << "Código: 105 – Produto: Refrigerante – Preço Unitário R$ 1,00 " << endl << endl;
	
	
	cout << "Digite o código e quantidade do produto: " << endl;
	cout << "Codigo: ";
	cin >> cod;
	while(cod!= 0){
		cout << "Quantidade: ";
		cin >> q;
		if(cod==100)
			val += q*1.7;
		if(cod == 101)
			val += q*2.3;
		if(cod==102)
			val+= q*2.6;
		if(cod==103)
			val+= q*2.4;
		if(cod==104)
			val += q*2.5;
		if(cod==105)
			val+= q;	
		
		cout << endl <<"Novo código: ";
		cin >> cod;
	}

	cout << "Valor total: " << val << endl; 

	return 0;
}
