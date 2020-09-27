#include <iostream>

using namespace std;

int main(){
	int n;
	int v[int(1e6)];
	cout << "Lê n números (n<10^6) e os imprime na ordem inversa" << endl;
	cout << "Digite n" << endl;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];

	for(int i=n-1; i>=0; i--)
		cout << v[i] << " ";
	cout << endl;
	
	return 0;
}
