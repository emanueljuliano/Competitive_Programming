#include <iostream>

using namespace std;

int main(){

	double v[6];
	cout << "Digite a nota do aluno em cada disciplina" << endl;
	for(int i=0; i<6; i++)
		cin >> v[i];

	double soma =0;
	for(int i=0; i<6; i++)
		soma += v[i];

	double media = soma/6.0;
	cout << "Media atual " << media << endl;	
	if(media>= 7.0)
		cout << "O aluno passou" << endl;
	else{
		cout << "Digite a nota do exame especial" << endl;
		double exame;
		cin >> exame;
		
		if((media*6 + exame*4)/10 >= 5.0)
			cout << "Passou com exame" << endl;
		else
			cout << "Não passou" << endl;
	}


	return 0;
}
