#include <iostream>

using namespace std;

int main(){
	int v[22]={0}, mais_ass = -1, menos_ass=1e9, q_tot=0, c_mais, c_menos;
	
	cout << "Digite o canal que a pessoa i assiste, para sair, digite 0" << endl;
	int n;
	cin >> n;
	while(n!=0){
		q_tot++;
		v[n] +=1;
		cin >> n;
	}

	for(int i=3; i<=21; i++){
		if(i!=3 and i!=7 and i!=10 and i!=17 and i!=21) continue;
		if(mais_ass < v[i]){
			mais_ass = v[i];
			c_mais = i;
		}
		if(menos_ass > v[i]){
			menos_ass = v[i];
			c_menos = i;
		}
	}

	cout << "O número de pessoas apuradas foi " << q_tot << endl;
	cout << v[3] << " pessoas assistem o canal 3" << endl;
	cout << v[7] << " pessoas assistem o canal 7" << endl;
	cout << v[10] << " pessoas assistem o canal 10" << endl;
	cout << v[17] << " pessoas assistem o canal 17" << endl;
	cout << v[21] << " pessoas assistem o canal 21" << endl;
	cout << "O canal mais assistido foi o " << c_mais << endl;
	cout << "O canal menos assistido foi o " << c_menos << endl;
	

	return 0;
}
