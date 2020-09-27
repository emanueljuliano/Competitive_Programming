#include <iostream>

using namespace std;

int main(){
	
	int v[10];
	for(int i=0; i<10; i++){
		cin >> v[i];
	}

	int soma1 = 0, soma2 = 0;

	for(int i=0; i<5; i++)
		soma1 += v[i];
	for(int i=5; i<10; i++)
		soma2 += v[i];

	if(soma1 == soma2)
		cout << "As somas são iguais" << endl;
	else
		cout << "As somas são diferentes" << endl;


	return 0;
}
