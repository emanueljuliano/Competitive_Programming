#include <iostream>

using namespace std;

int main(){
	int n, maior=0, menor=1e9, qmenor, qmaior;
	cout <<"Digite um número, 0 para parar" << endl;
	cin >> n; 
	while(n!=0){
		if(n<menor){
			menor = n;
			qmenor = 1;
		}
		else if(n==menor){
			qmenor++;
		}
		if(n>maior){
			maior = n;
			qmaior = 1;
		}
		else if(n==maior){
			qmaior++;
		}
		cin >> n;
	}
	cout << "O menor número " << menor << " aparece " << qmenor << " vezes" << endl;
	cout << "O maior número " << maior << " aparece " << qmaior << " vezes" << endl;

}
