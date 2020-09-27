#include <iostream>

using namespace std;

int main(){
	int n, idade, v[6]={0};
	cout << "Digite a idade de cada pessoa, -1 para parar" << endl;
	cin >> idade;
	while(idade!=-1){
		if(idade<=15)
			v[0]++;
		else if(idade<=30)
			v[1]++;
		else if(idade<=45)
			v[2]++;
		else if(idade<=60)
			v[3]++;
		else
			v[4]++;
		cin >> idade;
	}

	for(int i=0; i<5; i++){
		cout << "As pessoas na faixa hetária " <<i+1 <<" São " << v[i] << endl;
	}	

	cout << "A quantidade total de pessoas é " << v[0]+v[1]+v[2]+v[3]+v[4] << endl;
	
	int maxi = 0, faixa=0;
	for(int i=0; i<5; i++){
		if(v[i]>maxi){
			maxi = v[i];
			faixa = i+1;
		}
	}
	cout << "A faixa hetária com mais pessaos é " << faixa << endl;
	return 0;
}
