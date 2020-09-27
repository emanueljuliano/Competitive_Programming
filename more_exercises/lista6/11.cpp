#include <iostream>

using namespace std;


int main(){	
	int soma, nota;
	double media, alunos[30];

	for(int i=0; i<30; i++){
		cout << "Digite as notas do aluno " << i+1 << endl;
		soma = 0;
		for(int j=0; j<7; j++){
			cin >> nota;
			soma +=nota; 
		}
		alunos[i] = soma/7.0;
	}

	for(int i=0; i<30; i++){
		media = alunos[i];
		cout << "A média do aluno " << i+1 <<" foi " << media<< endl;
		if(media<4)
			cout << "logo, o aluno foi reprovado" << endl;
		else if(media<7)
			cout <<"Logo, o aluno pegou Exame Especial" << endl;
		else
			cout << "logo, o aluno foi aprovado" << endl;
	}
	return 0;
}
