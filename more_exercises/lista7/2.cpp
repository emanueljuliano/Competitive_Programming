#include <iostream>

using namespace std;

int main(){
	int v[20];
	for(int i=0; i<20; i++)
		cin >> v[i];

	int soma=0;
	for(int i=0; i<20; i++){
		if(v[i]%2==0)
			soma+= v[i];
	}	
	
	cout << "Soma: " << soma << endl;
	return 0;
}
