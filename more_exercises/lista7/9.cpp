#include <iostream>

using namespace std;


int main(){
	double visto[100000]={0}, v[100000];
	int n;
	cout << "Digite quantos elementos possui o vetor" << endl;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	for(int i=0; i<n-1; i++){
		if(visto[i]) 
			continue;
	
		int repeticoes = 0;
		for(int j=i; j<n; j++){
			if(v[i]==v[j]){
				repeticoes++;
				visto[j] = 1;
			}
		}
	
		if(repeticoes>0){
			cout << v[i] << " repete " << repeticoes << " vezes nas posiçoes ";
			for(int j=i; j<n; j++)
				if(v[i]==v[j])
					cout << j+1 << " ";
				
			cout << endl;
		}
	}
	return 0;
}
