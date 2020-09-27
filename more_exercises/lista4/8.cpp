#include <iostream>

using namespace std;

int main(){
	int n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	double media = (n1+n2+n3+n4+n5)/5;
	int resp;

	resp = int(media);

	switch(resp){
		case 0: case 1: case 2: case 3: case 4:
			cout <<"Reprovado" << endl;
			break;
		case 5: case 6:
			cout << "Exame Final" << endl;
			break;
		case 7: case 8: case 9: case 10:
			cout << "Aprovado" << endl;
	}

	return 0;
}
