#include <iostream>

using namespace std;

int main(){
	cout << "Numeros que (mod 11) restam 5" << endl;
	for(int i=1000; i<=2000; i++){
		if(i%11 == 5)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}
