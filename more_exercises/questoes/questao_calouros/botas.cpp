#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;

int main(){
	// Inicia vetor do pé direito e do pé esquerdo;
	int esq[MAXN], dir[MAXN];
	for(int i=0; i<MAXN; i++){
		esq[i] = 0;
		dir[i] = 0;
	}

	int n, tam;
	char pe;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> tam >> pe;
		
		if(pe=='D'){
			dir[tam]++;
		}
		else{
			esq[tam]++;
		}
	}

	int resposta = 0;
	for(int i=0; i<MAXN; i++){
		resposta += min(esq[i], dir[i]); // pares que podemos formar
	}

	cout << resposta << endl;

	exit(0);
}
