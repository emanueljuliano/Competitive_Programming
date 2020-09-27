#include <iostream>

using namespace std;

int main(){
	int a, b;
	cout << "Digite dois números, 0 0 para terminar" << endl;
	cin >> a >> b;
	while (a!=0 and b!= 0){
		if(a%b==0)
			cout << a << " é divisível por " << b << endl;
		cin >> a >> b;
	}
	return 0;
}
